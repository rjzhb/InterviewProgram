cmake_minimum_required(VERSION 3.16)
project(Asynchronously)

set(CMAKE_CXX_STANDARD 14)

add_executable(Asynchronously main.cpp)
target_link_libraries(Asynchronously pthread)