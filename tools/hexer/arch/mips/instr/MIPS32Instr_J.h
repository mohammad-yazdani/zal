//
// Created by Mohammad Yazdani on 2019-03-13.
//

#ifndef HEXER_MIPS32INSTR_J_H
#define HEXER_MIPS32INSTR_J_H

#include <arch/mips/instr/MIPS32Instruction.h>
#include <bitset>

class MIPS32Instr_J : public MIPS32Instruction
{
private:
    std::bitset<PADDR_SZ> paddr;
public:
    MIPS32Instr_J(instr32 instr_val, const std::bitset<6> &opcode, const std::bitset<26> &paddr);

    const std::bitset<26> &
    getPaddr() const;

    const std::string
    toString() override;
    const std::string
    prettyPrint() override;
};

#endif //HEXER_MIPS32INSTR_J_H
