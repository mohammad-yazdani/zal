//
// Created by Mohammad Yazdani on 2019-03-13.
//

#include "MIPS32Instr_R.h"

MIPS32Instr_R::MIPS32Instr_R(const instr32 &val,
                             const std::bitset<6> &opcode,
                             const std::bitset<5> &rs,
                             const std::bitset<5> &rt,
                             const std::bitset<5> &rd,
                             const std::bitset<6> &funct)
    : MIPS32Instruction(val, opcode), rs(rs), rt(rt), rd(rd), funct(funct)
{
    shamt = 0;
}

const std::string
MIPS32Instr_R::toString()
{
    auto pretty = opcode.to_string<char, std::string::traits_type, std::string::allocator_type>();
    pretty += " " + rs.to_string<char, std::string::traits_type, std::string::allocator_type>();
    pretty += " " + rt.to_string<char, std::string::traits_type, std::string::allocator_type>();
    pretty += " " + rd.to_string<char, std::string::traits_type, std::string::allocator_type>();
    pretty += " " + shamt.to_string<char, std::string::traits_type, std::string::allocator_type>();
    pretty += " " + funct.to_string<char, std::string::traits_type, std::string::allocator_type>();

    return std::string(pretty);
}

const std::string
MIPS32Instr_R::prettyPrint()
{
    auto op = funct_to_mnemonic(funct.to_ulong());
    std::string rds = "$" + std::to_string(rd.to_ulong());
    std::string rss = "$" + std::to_string(rs.to_ulong());
    std::string rts = "$" + std::to_string(rt.to_ulong());
    return op + " " + rds + " " + rss + " " + rts;
}
