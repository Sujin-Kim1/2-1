cmake_minimum_required(VERSION 3.5)
project(HW3)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(HW3
        BST.cpp
        BST.h
        main.cpp)
