//
// Created by Mohammad Yazdani on 2019-03-12.
//

#ifndef HEXER_PARSER_H
#define HEXER_PARSER_H

#include <vector>
#include <string>
#include "arch/mips/instr/MIPS32Instruction.h"

class Parser
{
private:
    std::vector<MIPS32Instruction *> instruction_queue;
public:
    unsigned int
    push(const std::string &line);

    std::vector<MIPS32Instruction *>
    flush();
};

#endif //HEXER_PARSER_H
