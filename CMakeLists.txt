cmake_minimum_required(VERSION 3.27)
project(TAD_dictionar)

set(CMAKE_CXX_STANDARD 17)

add_executable(TAD_dictionar "Proiect C++/main.cpp"
        "Proiect C++/Dictionar.h"
        "Proiect C++/Dictionar.cpp"
        "Proiect C++/IteratorDictionar.h"
        "Proiect C++/IteratorDictionar.cpp"
        Teste/TestExtins.h
        Teste/TextExtins.cpp
        Teste/TestScurt.h
        Teste/TestScurt.cpp)
