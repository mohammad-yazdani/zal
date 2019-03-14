//
// Created by Mohammad Yazdani on 2019-03-13.
//

#ifndef HEXER_MIPS32INSTRUCTION_H
#define HEXER_MIPS32INSTRUCTION_H

#include <arch/mips/instr/defs.h>
#include <bitset>
#include <string>
#include <vector>

class MIPS32Instruction
{
protected:
    instr32 instr_val;
    std::bitset<OPCODE_SZ> opcode;

    std::string
    funct_to_mnemonic(unsigned long funct);
    std::string
    opcode_to_mnemonic(unsigned long opcode);

public:
    MIPS32Instruction(instr32 instr_val, const std::bitset<6> &opcode);

    virtual const std::string
    toString();

    virtual const std::string
    prettyPrint();
};

#endif //HEXER_MIPS32INSTRUCTION_H
