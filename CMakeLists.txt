cmake_minimum_required(VERSION 3.21)
project(OOP_Assignment_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(NAVector)

add_executable(OOP_Assignment_3
        NAVector/main.cpp
        NAVector/NAVector.cpp
        NAVector/NAVector.h)
