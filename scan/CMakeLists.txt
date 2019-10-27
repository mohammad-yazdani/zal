cmake_minimum_required(VERSION 3.10)
project(scan)

set(CMAKE_C_STANDARD 90)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

include_directories(src/include)
include_directories(src/shared/file_io)
include_directories(src/shared/str)

add_executable(scan
		src/lib/token.c
        src/main.c
        src/shared/file_io/file_io_helpers.c
        src/lib/dfa.c
        src/shared/str/str_helper.c src/include/maximal_munch.h src/lib/maximal_munch.c 
        src/include/scan.h)

enable_testing()

add_test( split_test scan user/simple_add.c)
