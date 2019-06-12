cmake_minimum_required(VERSION 3.10)
project(scan)

set(CMAKE_C_STANDARD 90)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

add_executable(scan
		lib/token.c
        main.c)
