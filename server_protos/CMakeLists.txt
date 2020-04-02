cmake_minimum_required(VERSION 3.10)

project(server_protos)

add_library(${PROJECT_NAME} MyService.pb.cc MyService.pb.h)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROTOBUF_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC /opt/protobuf/usr/local/include)
target_link_directories(${PROJECT_NAME} PUBLIC /opt/protobuf/usr/local/lib)
target_link_libraries(${PROJECT_NAME} pthread protobuf)