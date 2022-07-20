cmake_minimum_required(VERSION 3.22)
project(Lab6_LinkedList)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab6_LinkedList
        LinkedListInterface.h
        main.cpp)
