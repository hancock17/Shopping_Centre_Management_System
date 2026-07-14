cmake_minimum_required(VERSION 3.31)
project(242_A2)

set(CMAKE_CXX_STANDARD 23)

add_executable(242_A2 main.cpp
        Business.cpp
        Business.h
        Employee.h
        Employee.cpp
        Restaurant.cpp
        Restaurant.h
        Shop.cpp
        Shop.h
        ShoppingCentre.cpp
        ShoppingCentre.h)
