#include <boost/asio.hpp>

#include "http_server/HttpServer.h"
#include "grpc_service/MyGRPCService.h"
#include "grpc_client/MyGRPCServiceClient.h"
#include "MyGRPCServiceDelegateImpl.h"
#include "HttpServerDelegateImpl.h"
#include "WatchDog.h"

int main(int argc, char** argv) {
    boost::asio::io_context main_ioc{1};
    boost::asio::io_context::work work(main_ioc);
    boost::asio::io_context grpc_ioc{1};
    boost::asio::io_context::work grpc_work(grpc_ioc);

    MyGRPCService grpc_service{"0.0.0.0:50051", std::make_unique<MyGRPCServiceDelegateImpl>(), main_ioc, grpc_ioc};
    MyGRPCServiceClient grpc_client("0.0.0.0:50051", grpc_ioc);
    HttpServer http_server{boost::asio::ip::make_address("127.0.0.1"), 8081, std::make_unique<HttpServerDelegateImpl>(grpc_client), main_ioc};

    // run io_contexts
    WatchDog watchdog{main_ioc, grpc_ioc};
    auto grpc_future = std::async(std::launch::async, [&]{grpc_ioc.run();});
    main_ioc.run();

    return 0;
}
