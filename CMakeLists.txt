cmake_minimum_required(VERSION 3.13)
project(zal)

set(CMAKE_C_STANDARD 90)

add_subdirectory(asm)
add_subdirectory(compile)
add_subdirectory(link)
add_subdirectory(parse)
add_subdirectory(scan)

