//
// Created by yazda on 6/17/2019.
//

#ifndef SCAN_STR_HELPER_H
#define SCAN_STR_HELPER_H

#include <stdlib.h>

extern const char CX_SYM[];
extern const char CX_ALPHABET[];

const int is_letter(char c);
const int is_digit(char c);
const int is_letter_or_digit(char c);
const int is_whitespace(char c);
const int is_sym(char c);

int empty_str(const char *arr);
unsigned long str_len(const char *arr);
char *reverse_str(const char *str);
char * add_char(char *str, char c, int prepend);

#endif //SCAN_STR_HELPER_H
