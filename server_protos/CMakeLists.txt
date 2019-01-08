cmake_minimum_required(VERSION 3.10)

project(server_protos)

find_package(Protobuf REQUIRED)
find_package(GRPC REQUIRED)

file(GLOB PROTO_FILES *.proto)
protobuf_generate_cpp(PROTO_SRC PROTO_HEADER ${PROTO_FILES})
grpc_generate_cpp(GRPC_SRCS GRPC_HDRS ${PROTO_SRC_DIR} ${PROTO_FILES})

add_library(${PROJECT_NAME} ${PROTO_SRC} ${PROTO_HEADER} ${GRPC_SRCS} ${GRPC_HDRS})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROTOBUF_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(${PROJECT_NAME} gRPC::grpc++ protobuf::libprotobuf)