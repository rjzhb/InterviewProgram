cmake_minimum_required(VERSION 3.16)
project(H2O)

set(CMAKE_CXX_STANDARD 14)

add_executable(H2O main.cpp)
target_link_libraries(H2O pthread)
