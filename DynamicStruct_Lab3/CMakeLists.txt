cmake_minimum_required(VERSION 3.24)
project(DynamicStruct_Lab1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_GENERATOR "Ninja")
message("generator is set to ${CMAKE_GENERATOR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(.)

add_executable(DynamicStruct_Lab3
        OOP_Set_Antonov.cpp
        SetLab3_Antonov.cpp
        SetLab3_Antonov.h)
