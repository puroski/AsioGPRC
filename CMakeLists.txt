cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_subdirectory(server_protos)
add_subdirectory(server)
add_subdirectory(http_client)
