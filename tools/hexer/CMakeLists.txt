cmake_minimum_required(VERSION 3.13)
project(hexer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(arch/mips/instr)

add_executable(hexer
        arch/mips/instr/defs.h
        arch/mips/instr/MIPS32Instr_I.cc
        arch/mips/instr/MIPS32Instr_I.h
        arch/mips/instr/MIPS32Instr_J.cc
        arch/mips/instr/MIPS32Instr_J.h
        arch/mips/instr/MIPS32Instr_R.cc
        arch/mips/instr/MIPS32Instr_R.h
        arch/mips/instr/MIPS32Instruction.cc
        arch/mips/instr/MIPS32Instruction.h
        main.cc
        Parser.cc
        Parser.h)
