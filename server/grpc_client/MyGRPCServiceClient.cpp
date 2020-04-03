/*
 *
 * Copyright 2015 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "MyGRPCServiceClient.h"

#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include <grpc/support/log.h>
#include <thread>

using grpc::Channel;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;
using server::Request;
using server::Response;
using server::MyService;

#include <tao/json.hpp>

// struct for keeping state and data information
struct AsyncClientCall {
    // Container for the data we expect from the server.
    Response reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // Storage for the status of the RPC upon completion.
    Status status;

    std::unique_ptr<ClientAsyncResponseReader<Response>> response_reader;

    std::function<void(const std::string&)> callback;
};

MyGRPCServiceClient::MyGRPCServiceClient(const std::string& address, boost::asio::io_context& grpc_ioc)
        : stub_(MyService::NewStub(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials())))
        , grpc_ioc_{grpc_ioc} {
    thread_ = std::thread(&MyGRPCServiceClient::handle_response, this);
}

MyGRPCServiceClient::~MyGRPCServiceClient() {
  is_running_ = false;
  thread_.join();
}

// Assembles the client's payload and sends it to the server.
void MyGRPCServiceClient::do_something(const std::string &action, std::function<void(const std::string&)> callback) {
    // Data we are sending to the server.
    auto json = tao::json::from_string(action);
    Request request;
    request.set_action(json.as<std::string>("string"));
    request.set_number(json.as<int>("number"));

    // Call object to store rpc data
    AsyncClientCall* call = new AsyncClientCall;
    call->callback = std::move(callback);

    // stub_->PrepareAsyncDoSomething() creates an RPC object, returning
    // an instance to store in "call" but does not actually start the RPC
    // Because we are using the asynchronous API, we need to hold on to
    // the "call" instance in order to get updates on the ongoing RPC.
    call->response_reader =
            stub_->PrepareAsyncdo_something(&call->context, request, &cq_);

    // StartCall initiates the RPC call
    call->response_reader->StartCall();

    // Request that, upon completion of the RPC, "reply" be updated with the
    // server's response; "status" with the indication of whether the operation
    // was successful. Tag the request with the memory address of the call object.
    call->response_reader->Finish(&call->reply, &call->status, (void*)call);
}

void MyGRPCServiceClient::handle_response() {
    while (is_running_) {
        void* got_tag;
        bool ok = false;

        // Block until the next result is available in the completion queue "cq".
        auto result = cq_.AsyncNext(&got_tag, &ok, std::chrono::system_clock::now() + std::chrono::milliseconds(10));
        if (result == grpc::CompletionQueue::NextStatus::GOT_EVENT) {
            // The tag in this example is the memory location of the call object
            AsyncClientCall* call = static_cast<AsyncClientCall*>(got_tag);

            // Verify that the request was completed successfully. Note that "ok"
            // corresponds solely to the request for updates introduced by Finish().
            GPR_ASSERT(ok);

            call->callback(call->status.ok() ? call->reply.result() : "RPC failed!");

            // Once we're complete, deallocate the call object.
            delete call;
        }
        handle_response();
    };
}


