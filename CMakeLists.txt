cmake_minimum_required(VERSION 3.22)
project(PIC23)

set(CMAKE_CXX_STANDARD 20)

add_executable(PIC23
        main.cpp
        Labor_1/labor1.cpp
        Labor_1/globals.cpp
        Labor_1/dateiverwaltung.cpp
        LAbor_2/labor2.cpp LAbor_2/labor2.hpp LAbor_2/Teil_A/lab2a.cpp LAbor_2/Teil_A/lab2a.hpp LAbor_2/Teil_B/lab2b.cpp LAbor_2/Teil_B/lab2b.hpp)
