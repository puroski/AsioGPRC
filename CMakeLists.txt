cmake_minimum_required(VERSION 3.10)

project(conversion_benchmark)

set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(CMAKE_CXX_STANDARD 17)

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

include(InstallTaoJson.cmake)

add_subdirectory(http_client)
add_subdirectory(server_protos)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} server_protos)
add_dependencies(${PROJECT_NAME} taojson)