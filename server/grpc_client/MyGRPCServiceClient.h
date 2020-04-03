//
// Created by naum on 07/01/2019.
//

#ifndef PROJECT_MYGRPCSERVICECLIENT_H
#define PROJECT_MYGRPCSERVICECLIENT_H

#include <functional>

#include <boost/asio.hpp>
#include <grpcpp/grpcpp.h>

#include "MyService.grpc.pb.h"

class MyGRPCServiceClient final {
public:
    explicit MyGRPCServiceClient(const std::string& address, boost::asio::io_context& grpc_ioc);
  ~MyGRPCServiceClient();

    // Assembles the client's payload and sends it to the server.
    void do_something(const std::string &action, std::function<void(const std::string&)> callback);

private:

    void handle_response();

    // Out of the passed in Channel comes the stub, stored here, our view of the
    // server's exposed services.
    std::unique_ptr<server::MyService::Stub> stub_;

    // The producer-consumer queue we use to communicate asynchronously with the gRPC runtime.
    grpc::CompletionQueue cq_;

    boost::asio::io_context& grpc_ioc_;
    bool is_running_ = true;
    std::thread thread_;
};

#endif //PROJECT_MYGRPCSERVICECLIENT_H
