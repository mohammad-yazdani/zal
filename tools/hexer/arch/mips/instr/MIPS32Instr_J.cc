//
// Created by Mohammad Yazdani on 2019-03-13.
//

#include "MIPS32Instr_J.h"

MIPS32Instr_J::MIPS32Instr_J(instr32 instr_val, const std::bitset<6> &opcode, const std::bitset<26> &paddr)
    : MIPS32Instruction(instr_val, opcode), paddr(paddr) {}

const std::bitset<26> &
MIPS32Instr_J::getPaddr() const
{
    return paddr;
}

const std::string
MIPS32Instr_J::toString()
{
    auto pretty = opcode.to_string<char, std::string::traits_type, std::string::allocator_type>();
    pretty += " " + paddr.to_string<char, std::string::traits_type, std::string::allocator_type>();

    return std::string(pretty);
}

const std::string
MIPS32Instr_J::prettyPrint()
{
    auto op = opcode_to_mnemonic(opcode.to_ulong());
    std::string paddrs = std::to_string(paddr.to_ulong());
    return op + " " + paddrs;
}
