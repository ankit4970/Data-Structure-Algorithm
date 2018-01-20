cmake_minimum_required(VERSION 3.8)
project(interview)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp linkedlist.cpp algorithm.cpp tree.cpp bits.cpp string.cpp matrix.cpp stack.cpp common.h sort.cpp graph.cpp pointer.cpp array.cpp memory.cpp backtracking.cpp dynamicprogramming.cpp functionPointer.cpp)
add_executable(interview ${SOURCE_FILES})