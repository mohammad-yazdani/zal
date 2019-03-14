//
// Created by Mohammad Yazdani on 2019-03-13.
//

#ifndef HEXER_MIPS32INSTR_I_H
#define HEXER_MIPS32INSTR_I_H

#include <arch/mips/instr/MIPS32Instruction.h>
#include <bitset>

class MIPS32Instr_I : public MIPS32Instruction
{
private:
    std::bitset<VAR_SZ> rs;
    std::bitset<VAR_SZ> rt;
    std::bitset<IMM_SZ> imm;
public:
    MIPS32Instr_I(const instr32 &val,
                  const std::bitset<6> &opcode,
                  const std::bitset<5> &rs,
                  const std::bitset<5> &rt,
                  const std::bitset<16> &imm);

    const std::bitset<6> &
    getOpcode() const;
    const std::bitset<5> &
    getRs() const;
    const std::bitset<5> &
    getRt() const;
    const std::bitset<16> &
    getImm() const;

    const std::string
    toString() override;
    const std::string
    prettyPrint() override;
};

#endif //HEXER_MIPS32INSTR_I_H
