cmake_minimum_required(VERSION 3.13)
project(generator)

set(CMAKE_C_STANDARD 90)

include_directories(.)

add_executable(generator
        main.c)
