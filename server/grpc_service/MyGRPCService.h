//
// Created by naum on 07/01/2019.
//

#ifndef PROJECT_MYGRPCSERVICE_H
#define PROJECT_MYGRPCSERVICE_H

#include <grpcpp/grpcpp.h>
#include <boost/asio.hpp>

#include "MyService.grpc.pb.h"

#include "MyGRPCServiceDelegate.h"

class MyGRPCService final {
public:
    MyGRPCService(const std::string& server_address, std::unique_ptr<MyGRPCServiceDelegate> delegate,
                  boost::asio::io_context& main_ioc, boost::asio::io_context& grpc_ioc);
    ~MyGRPCService();

private:
    void handle_rpcs();

    boost::asio::io_context& main_ioc_;
    boost::asio::io_context& grpc_ioc_;
    std::unique_ptr<MyGRPCServiceDelegate> delegate_;
    std::unique_ptr<grpc::ServerCompletionQueue> cq_;
    server::MyService::AsyncService service_;
    std::unique_ptr<grpc::Server> server_;
};

#endif //PROJECT_MYGRPCSERVICE_H
