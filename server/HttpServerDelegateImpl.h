//
// Created by naum on 07/01/2019.
//

#ifndef PROJECT_HTTPSERVERDELEGATEIMPL_H
#define PROJECT_HTTPSERVERDELEGATEIMPL_H

#include "http_server/HttpServerDelegate.h"

class MyGRPCServiceClient;

class HttpServerDelegateImpl : public HttpServerDelegate {
public:
    HttpServerDelegateImpl(MyGRPCServiceClient& grpc_client);
    std::size_t request_count() override;
    std::time_t now() override;

    void do_something(const std::string& action, std::function<void(const std::string&)> callback) override;

private:
    MyGRPCServiceClient& grpc_client_;
};


#endif //PROJECT_HTTPSERVERDELEGATEIMPL_H
