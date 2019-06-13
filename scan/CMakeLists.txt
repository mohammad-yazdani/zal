cmake_minimum_required(VERSION 3.10)
project(scan)

set(CMAKE_C_STANDARD 90)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)
include_directories(shared)

add_executable(scan
		lib/token.c
        main.c shared/file_io/file_io_helpers.h shared/file_io/file_io_helpers.c)

enable_testing()

add_test( split_test scan misc/simple_add.c)
