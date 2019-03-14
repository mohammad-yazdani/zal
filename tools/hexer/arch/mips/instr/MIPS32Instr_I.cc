//
// Created by Mohammad Yazdani on 2019-03-13.
//

#include "MIPS32Instr_I.h"

MIPS32Instr_I::MIPS32Instr_I(const instr32 &val,
                             const std::bitset<6> &opcode,
                             const std::bitset<5> &rs,
                             const std::bitset<5> &rt,
                             const std::bitset<16> &imm)
    : MIPS32Instruction(val, opcode), rs(rs), rt(rt), imm(imm) {}

const std::bitset<6> &
MIPS32Instr_I::getOpcode() const
{
    return opcode;
}
const std::bitset<5> &
MIPS32Instr_I::getRs() const
{
    return rs;
}
const std::bitset<5> &
MIPS32Instr_I::getRt() const
{
    return rt;
}
const std::bitset<16> &
MIPS32Instr_I::getImm() const
{
    return imm;
}

const std::string
MIPS32Instr_I::toString()
{
    auto pretty = opcode.to_string<char, std::string::traits_type, std::string::allocator_type>();
    pretty += " " + rs.to_string<char, std::string::traits_type, std::string::allocator_type>();
    pretty += " " + rt.to_string<char, std::string::traits_type, std::string::allocator_type>();
    pretty += " " + imm.to_string<char, std::string::traits_type, std::string::allocator_type>();

    return std::string(pretty);
}

const std::string
MIPS32Instr_I::prettyPrint()
{
    auto op = opcode_to_mnemonic(opcode.to_ulong());
    std::string rts = "$" + std::to_string(rt.to_ulong());
    std::string rss = "$" + std::to_string(rs.to_ulong());
    std::string imms = "[" + std::to_string(imm.to_ulong()) + "]";
    return op + " " + rts + " " + rss + " " + imms;
}
