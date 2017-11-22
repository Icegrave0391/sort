cmake_minimum_required(VERSION 3.8)
project(sort)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c sort_function.c sort_function.h)
add_executable(sort ${SOURCE_FILES})