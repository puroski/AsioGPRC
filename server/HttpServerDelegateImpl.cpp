//
// Created by naum on 07/01/2019.
//

#include "HttpServerDelegateImpl.h"
#include "grpc_client/MyGRPCServiceClient.h"

HttpServerDelegateImpl::HttpServerDelegateImpl(MyGRPCServiceClient& grpc_client)
    : grpc_client_{grpc_client} {}

std::size_t HttpServerDelegateImpl::request_count() {
    static std::size_t count = 0;
    return ++count;
}

std::time_t HttpServerDelegateImpl::now() {
    return std::time(0);
}

void HttpServerDelegateImpl::do_something(const std::string& action, std::function<void(const std::string&)> callback) {
    grpc_client_.do_something(action, std::move(callback));
}