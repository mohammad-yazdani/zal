cmake_minimum_required(VERSION 3.10)
project(lexer)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

include_directories(src/include)
include_directories(src/shared/file_io)
include_directories(src/shared/str)

add_executable(lexer
		src/lib/token.c
        src/lib/scan.c
        src/lib/stream.c
        src/main.c
        src/shared/file_io/file_io_helpers.c
        src/lib/dfa.c
        src/shared/str/str_helper.c 
        # src/lib/maximal_munch.c 
        src/include/scan.h
        src/include/stream.h)

enable_testing()

add_test( split_test lexer user/simple_add.c)
