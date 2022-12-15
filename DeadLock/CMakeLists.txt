cmake_minimum_required(VERSION 3.16)
project(DeadLock)

set(CMAKE_CXX_STANDARD 14)

add_executable(DeadLock main.cpp)
TARGET_LINK_LIBRARIES(DeadLock pthread)