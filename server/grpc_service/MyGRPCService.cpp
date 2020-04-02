//
// Created by naum on 07/01/2019.
//

#include "MyGRPCService.h"

#include <memory>
#include <iostream>
#include <string>
#include <thread>

#include <grpcpp/grpcpp.h>
#include <grpc/support/log.h>

#include "MyService.grpc.pb.h"

using grpc::Server;
using grpc::ServerAsyncResponseWriter;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerCompletionQueue;
using grpc::Status;
using server::Request;
using server::Response;
using server::MyService;

// TODO: should be a template that handles all type of service requests
// Class encompasing the state and logic needed to serve a request.
class CallData {
public:
    // Take in the "service" instance (in this case representing an asynchronous
    // server) and the completion queue "cq" used for asynchronous communication
    // with the gRPC runtime.
    CallData(MyService::AsyncService* service, ServerCompletionQueue* cq, boost::asio::io_context& main_ioc, MyGRPCServiceDelegate& delegate)
            : service_(service), cq_(cq), responder_(&ctx_), status_(CREATE), main_ioc_{main_ioc}, delegate_{delegate} {
        // Invoke the serving logic right away.
        Proceed();
    }

    void Proceed() {
        if (status_ == CREATE) {
            // Make this instance progress to the PROCESS state.
            status_ = PROCESS;

            // As part of the initial CREATE state, we *request* that the system
            // start processing SayHello requests. In this request, "this" acts are
            // the tag uniquely identifying the request (so that different CallData
            // instances can serve different requests concurrently), in this case
            // the memory address of this CallData instance.
            service_->Requestdo_something(&ctx_, &request_, &responder_, cq_, cq_,
                                         this);
        } else if (status_ == PROCESS) {
            // Spawn a new CallData instance to serve new clients while we process
            // the one for this CallData. The instance will deallocate itself as
            // part of its FINISH state.
            new CallData(service_, cq_, main_ioc_, delegate_);

            // CHANGE: process request on main ioc
            main_ioc_.post([&](){
                auto result = delegate_.do_something(std::to_string(request_.number()));
                reply_.set_result(result);

                // And we are done! Let the gRPC runtime know we've finished, using the
                // memory address of this instance as the uniquely identifying tag for
                // the event.
                status_ = FINISH;
                responder_.Finish(reply_, Status::OK, this);
            });
        } else {
            GPR_ASSERT(status_ == FINISH);
            // Once in the FINISH state, deallocate ourselves (CallData).
            delete this;
        }
    }

private:
    // The means of communication with the gRPC runtime for an asynchronous
    // server.
    MyService::AsyncService* service_;
    // The producer-consumer queue where for asynchronous server notifications.
    ServerCompletionQueue* cq_;
    // Context for the rpc, allowing to tweak aspects of it such as the use
    // of compression, authentication, as well as to send metadata back to the
    // client.
    ServerContext ctx_;

    // What we get from the client.
    Request request_;
    // What we send back to the client.
    Response reply_;

    // The means to get back to the client.
    ServerAsyncResponseWriter<Response> responder_;

    // Let's implement a tiny state machine with the following states.
    enum CallStatus { CREATE, PROCESS, FINISH };
    CallStatus status_;  // The current serving state.

    boost::asio::io_context& main_ioc_;
    MyGRPCServiceDelegate& delegate_;
};

MyGRPCService::MyGRPCService(const std::string& server_address, std::unique_ptr<MyGRPCServiceDelegate> delegate,
                             boost::asio::io_context& main_ioc, boost::asio::io_context& grpc_ioc)
        : main_ioc_{main_ioc}
        , grpc_ioc_{grpc_ioc}
        , delegate_{std::move(delegate)} {
    ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    // Register "service_" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *asynchronous* service.
    builder.RegisterService(&service_);
    // Get hold of the completion queue used for the asynchronous communication
    // with the gRPC runtime.
    cq_ = builder.AddCompletionQueue();
    // Finally assemble the server.
    server_ = builder.BuildAndStart();

    handle_rpcs();
}

MyGRPCService::~MyGRPCService() {
    server_->Shutdown();
    // Always shutdown the completion queue after the server.
    cq_->Shutdown();
}

void MyGRPCService::handle_rpcs() {
    grpc_ioc_.post([&]() {
        new CallData(&service_, cq_.get(), main_ioc_, *delegate_);
        void* tag;  // uniquely identifies a request.
        bool ok;

        auto result = cq_->AsyncNext(&tag, &ok, std::chrono::system_clock::now() + std::chrono::milliseconds(10));
        if (result == grpc::CompletionQueue::NextStatus::GOT_EVENT) {
            static_cast<CallData*>(tag)->Proceed();
        }

        handle_rpcs();
    });
}