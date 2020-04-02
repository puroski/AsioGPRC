cmake_minimum_required(VERSION 3.10)

project(AsioGRPC)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

include_directories(/home/nomenas/Projects/Http2MqttBridge/.build/external/include)

add_subdirectory(server_protos)
add_subdirectory(server)
add_subdirectory(http_client)
