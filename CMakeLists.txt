cmake_minimum_required(VERSION 3.8)
project(interview)

set(CMAKE_CXX_STANDARD 11)

include_directories(includes)

set(SOURCE_FILES
        src/main.cpp
        src/array.cpp
        src/backtracking.cpp
        src/dynamicprogramming.cpp
        src/linkedlist.cpp
        src/algorithm.cpp
        src/tree.cpp
        src/bits.cpp
        src/string.cpp
        src/matrix.cpp
        src/stack.cpp
        src/graph.cpp
        src/sort.cpp
        src/utility.cpp
        includes/graph.h
        includes/array.h
        includes/backtracking.h
        includes/dynamicprogramming.h
        includes/sort.h
        includes/linkedlist.h
        includes/utility.h
        includes/myalgorithm.h
        includes/matrix.h
        includes/mystack.h
        includes/mystring.h
        includes/trie.h
        )

add_executable(interview ${SOURCE_FILES})