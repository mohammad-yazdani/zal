//
// Created by yazda on 6/13/2019.
//

#ifndef SCAN_DFA_H
#define SCAN_DFA_H

#include <str_helper.h>

#define STATES 1
#define WHITE_SPACE 6

typedef enum CX_ACCEPTING {
    START, INVALID,
    SPACE, TAB, NEWLINE, COMMENT, WHITESPACE,
    ID, NUM, LPAREN, RPAREN, LBRACE, RBRACE, RETURN, IF,
    ELSE, WHILE, PRINTLN, WAIN, BECOMES, INT, EQ, NE, LT,
    GT, LE, GE, PLUS, MINUS, STAR, SLASH, PCT, COMMA, SEMI,
    NEW, DELETE, LBRACK, RBRACK, AMP, NULLL, ZERO, BANG
} ACCEPTING;

int transition(ACCEPTING state, char in_char);

int is_in_alphabet(int state);

#endif //SCAN_DFA_H
