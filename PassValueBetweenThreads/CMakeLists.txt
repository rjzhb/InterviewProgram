cmake_minimum_required(VERSION 3.16)
project(PassValueBetweenThreads)

set(CMAKE_CXX_STANDARD 14)

add_executable(PassValueBetweenThreads main.cpp)
target_link_libraries(PassValueBetweenThreads pthread)