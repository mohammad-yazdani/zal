//
// Created by Mohammad Yazdani on 2019-03-13.
//

#ifndef HEXER_MIPS32INSTR_R_H
#define HEXER_MIPS32INSTR_R_H

#include <arch/mips/instr/MIPS32Instruction.h>
#include <bitset>

class MIPS32Instr_R : public MIPS32Instruction
{
private:
    std::bitset<VAR_SZ> rs;
    std::bitset<VAR_SZ> rt;
    std::bitset<VAR_SZ> rd;
    std::bitset<VAR_SZ> shamt;
    std::bitset<OPCODE_SZ> funct;
public:
    MIPS32Instr_R(const instr32 &val,
                  const std::bitset<6> &opcode,
                  const std::bitset<5> &rs,
                  const std::bitset<5> &rt,
                  const std::bitset<5> &rd,
                  const std::bitset<6> &funct);

    const std::string
    toString() override;

    const std::string
    prettyPrint() override;
};

#endif //HEXER_MIPS32INSTR_R_H
