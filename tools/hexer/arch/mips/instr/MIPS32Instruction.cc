//
// Created by Mohammad Yazdani on 2019-03-13.
//

#include "MIPS32Instruction.h"

MIPS32Instruction::MIPS32Instruction(instr32 instr_val, const std::bitset<6> &opcode)
    : instr_val(instr_val), opcode(opcode) {}

const std::string
MIPS32Instruction::toString()
{
    return "undefined";
}

const std::string
MIPS32Instruction::prettyPrint()
{
    return "undefined";
}

std::string
MIPS32Instruction::funct_to_mnemonic(unsigned long funct)
{
    switch (funct)
    {
        case ADD:return "add";
        case ADDU:return "addu";
        case AND:return "and";
        case DIV:return "div";
        case DIVU:return "divu";
        case JR:return "jr";
        case MFHI:return "mfhi";
        case MFLO:return "mflo";
        case MTHI:return "mthi";
        case MTLO:return "mtlo";
        case MULT:return "mult";
        case MULTU:return "multu";
        case NOR:return "nor";
        case OR:return "or";
        case SLL:return "ssl";
        case SLT:return "slt";
        case SLTU:return "sltu";
        case SRA:return "sra";
        case SRL:return "srl";
        case SUB:return "sub";
        case SUBU:return "subu";
        case XOR:return "xor";
        default:return "undefined";
    }
}

std::string
MIPS32Instruction::opcode_to_mnemonic(unsigned long opcode)
{
    switch (opcode)
    {
        case J:return "j";
        case JAL:return "jal";
        case BEQ:return "beq";
        case BNE:return "bne";
        case BLEZ:return "blez";
        case BGTZ:return "bgtz";
        case ADDI:return "addi";
        case ADDIU:return "addiu";
        case SLTI:return "slti";
        case SLTIU:return "sltiu";
        case ANDI:return "andi";
        case ORI:return "ori";
        case LUI:return "lui";
        case MFC0:return "mfc0";
        case LB:return "lb";
        case LW:return "lw";
        case LBU:return "lbu";
        case LHU:return "lhu";
        case SB:return "sb";
        case SH:return "sh";
        case SW:return "sw";
        default:return "undefined";
    }
}
