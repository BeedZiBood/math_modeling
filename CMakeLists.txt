cmake_minimum_required(VERSION 3.28)
project(math_modeling)

set(CMAKE_CXX_STANDARD 20)

add_executable(math_modeling
        main.cpp
        solving_cubic_equation.cpp
        solving_cubic_equation.h
        comparison_between_doubles.h
        finding_x2_and_x3.cpp
        finding_x2_and_x3.h
)
