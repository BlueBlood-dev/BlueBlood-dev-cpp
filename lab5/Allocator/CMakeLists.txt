cmake_minimum_required(VERSION 3.20)
project(Allocator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Allocator main.cpp MyAllocator.h MyTempAll.h)
