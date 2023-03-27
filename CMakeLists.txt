cmake_minimum_required(VERSION 3.22)
project(PIC23)

set(CMAKE_CXX_STANDARD 20)

add_executable(PIC23
        main.cpp
        Labor_1/labor1.cpp
        globals.cpp
        Labor_1/dateiverwaltung.cpp
        Labor_2/labor2.cpp
        Labor_2/Teil_A/lap2a.cpp
        Labor_2/dishlib/dishlib.cpp
        )

#Lab2 Teil B Aufgabe 1
add_subdirectory(Labor_2)
target_include_directories(PIC23 PUBLIC Labor_2)
target_link_libraries(PIC23
        dishlib
        )