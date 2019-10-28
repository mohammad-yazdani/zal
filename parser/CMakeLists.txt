cmake_minimum_required(VERSION 3.13)
project(parser)

set(CMAKE_C_STANDARD 90)

include_directories(.)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

add_executable(parser
        main.c)
