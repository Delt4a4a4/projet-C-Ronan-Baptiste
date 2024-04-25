cmake_minimum_required(VERSION 3.27)
project(projet_C_Ronan_Baptiste C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c
        cdataframe.c
        cdataframe.h
        column.h
        column.c
)
