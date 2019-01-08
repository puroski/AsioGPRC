cmake_minimum_required(VERSION 3.10)

project(server)

find_package(Boost REQUIRED)

set(SOURCE_FILES
        main.cpp
        http_server/HttpServer.cpp
        http_server/HttpServer.h
        grpc_service/MyGRPCService.cpp
        grpc_service/MyGRPCService.h
        grpc_service/MyGRPCServiceDelegate.h
        grpc_client/MyGRPCServiceClient.cpp
        grpc_client/MyGRPCServiceClient.h
        MyGRPCServiceDelegateImpl.cpp
        MyGRPCServiceDelegateImpl.h
        HttpServerDelegateImpl.cpp
        HttpServerDelegateImpl.h
        WatchDog.cpp
        WatchDog.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} server_protos)
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
target_compile_definitions(${PROJECT_NAME} PRIVATE BOOST_ERROR_CODE_HEADER_ONLY)
