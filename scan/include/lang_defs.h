//
// Created by yazda on 6/13/2019.
//

#ifndef SCAN_LANG_DEFS_H
#define SCAN_LANG_DEFS_H

#define STATES 1
#define WHITE_SPACE 6

enum CX_ACCEPTING {
    START, INVALID,
    SPACE, TAB, NEWLINE, COMMENT, WHITESPACE,
    ID, NUM, LPAREN, RPAREN, LBRACE, RBRACE, RETURN, IF,
    ELSE, WHILE, PRINTLN, WAIN, BECOMES, INT, EQ, NE, LT,
    GT, LE, GE, PLUS, MINUS, STAR, SLASH, PCT, COMMA, SEMI,
    NEW, DELETE, LBRACK, RBRACK, AMP, NULL, ZERO, BANG
};

const char CX_SYM[] = {'=', '<', '>'};

const char CX_ALPHABET[] = {'!', '.', ';', '$', ',', '(', ')', 'a',
                      'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                      'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
                      'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                      'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
                      'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};




#endif //SCAN_LANG_DEFS_H
