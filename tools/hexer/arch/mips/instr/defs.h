//
// Created by Mohammad Yazdani on 2019-03-13.
//

#ifndef HEXER_DEFS_H
#define HEXER_DEFS_H

#include <cstdint>
#include <string>

#define OPCODE_SZ 6
#define VAR_SZ 5
#define IMM_SZ 16
#define PADDR_SZ 26

#define OPCODE_MASK 0xFC000000
#define RS_MASK 0x03E00000
#define RT_MASK 0x001F0000
#define RD_MASK 0x0000F800
#define FUNCT_MASK 0x0000003F
#define IMM_MASK 0x0000FFFF
#define PADDR_MASK 0x03FFFFFF

#define ADD 0x20
#define ADDU 0x21
#define AND 0x24
#define DIV 0x1A
#define DIVU 0x1B
#define JR 0x08
#define MFHI 0x10
#define MFLO 0x12
#define MTHI 0x11
#define MTLO 0x13
#define MULT 0x18
#define MULTU 0x19
#define NOR 0x27
#define OR 0x25
#define SLL 0x00
#define SLT 0x2A
#define SLTU 0x2B
#define SRA 0x03
#define SRL 0x02
#define SUB 0x22
#define SUBU 0x23
#define XOR 0x26

#define J 0x02
#define JAL 0x03
#define BEQ 0x04
#define BNE 0x05
#define BLEZ 0x06
#define BGTZ 0x07
#define ADDI 0x08
#define ADDIU 0x09
#define SLTI 0x0A
#define SLTIU 0x0B
#define ANDI 0x0C
#define ORI 0x0D
#define LUI 0x0F
#define MFC0 0x10
#define LB 0x20
#define LW 0x23
#define LBU 0x24
#define LHU 0x25
#define SB 0x28
#define SH 0x29
#define SW 0x2B

typedef std::uint32_t instr32;

#endif //HEXER_DEFS_H
