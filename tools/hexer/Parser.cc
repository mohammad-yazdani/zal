//
// Created by Mohammad Yazdani on 2019-03-12.
//

#include <Parser.h>
#include <sstream>
#include <arch/mips/instr/defs.h>
#include <arch/mips/instr/MIPS32Instr_R.h>
#include <arch/mips/instr/MIPS32Instr_I.h>
#include <arch/mips/instr/MIPS32Instr_J.h>
#include "Parser.h"

unsigned int
Parser::push(const std::string &line)
{
    std::stringstream ss;
    instr32 instr, opcode, rs, rt, rd, funct, imm, paddr;
    MIPS32Instruction *fetched;

    ss << std::hex << line;
    ss >> instr;

    auto shift = 32 - OPCODE_SZ;
    opcode = (instr & OPCODE_MASK) >> shift;
    shift -= VAR_SZ;

    if (opcode == 0x0 || opcode == 0x10)
    {
        // TODO : R type
        rs = (instr & RS_MASK) >> shift;
        shift -= VAR_SZ;
        rt = (instr & RT_MASK) >> shift;
        shift -= VAR_SZ;
        rd = (instr & RD_MASK) >> shift;
        funct = instr & FUNCT_MASK;
        fetched = new MIPS32Instr_R(instr, opcode, rs, rt, rd, funct);
    }
    else if (opcode == 0x02 || opcode == 0x03)
    {
        // TODO : J type
        paddr = instr & PADDR_MASK;

        fetched = new MIPS32Instr_J(instr, opcode, paddr);
    }
    else
    {
        // TODO : I type
        rs = (instr & RS_MASK) >> shift;
        shift -= VAR_SZ;
        rt = (instr & RT_MASK) >> shift;
        imm = instr & IMM_MASK;

        fetched = new MIPS32Instr_I(instr, opcode, rs, rt, imm);
    }

    instruction_queue.emplace_back(fetched);

    return 0;
}

std::vector<MIPS32Instruction *>
Parser::flush()
{
    return instruction_queue;
}
