cmake_minimum_required(VERSION 3.24)
project(DynamicStruct_Lab5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_GENERATOR "Ninja")
message("generator is set to ${CMAKE_GENERATOR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(.)

add_executable(DynamicStruct_Lab5
        Set_Cont_Set_Antonov.cpp
        SetLab5_Antonov.cpp
        SetLab5_Antonov.h)
