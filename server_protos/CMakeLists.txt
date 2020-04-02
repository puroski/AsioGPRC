cmake_minimum_required(VERSION 3.10)

project(server_protos)


#file(GLOB PROTO_FILES *.proto)
#protobuf_generate_cpp(PROTO_SRC PROTO_HEADER ${PROTO_FILES})
#grpc_generate_cpp(GRPC_SRCS GRPC_HDRS ${PROTO_SRC_DIR} ${PROTO_FILES})

add_library(${PROJECT_NAME} MyService.pb.h MyService.pb.cc MyService.grpc.pb.cc MyService.grpc.pb.h)
target_include_directories(${PROJECT_NAME} PUBLIC . /opt/protobuf/usr/local/include /home/nomenas/Projects/grpc/include)
target_link_directories(${PROJECT_NAME} PUBLIC /opt/protobuf/usr/local/lib /home/nomenas/Projects/grpc/cmake/build)
target_link_libraries(${PROJECT_NAME} protobuf gpr grpc++ pthread)