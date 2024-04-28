cmake_minimum_required(VERSION 3.28)
project(math_modeling)

set(CMAKE_CXX_STANDARD 14)

add_executable(math_modeling
        main.cpp
        system_of_equations.cpp
        system_of_equations.h
        zeroin.cpp
        zeroin.h
)
