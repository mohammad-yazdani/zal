//
// Created by yazda on 6/17/2019.
//

#include "str_helper.h"

const char CX_SYM[] = {'=', '<', '>'};

// TODO : Where to use?
const char CX_ALPHABET[] = {'!', '.', ';', '$', ',', '(', ')', 'a',
                            'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                            'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
                            'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                            'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
                            'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

const int
is_letter(const char c)
{
    return (c >= 65 && c <= 90);
}

const int
is_digit(const char c)
{
    return (c >= 48 && c <= 57);
}

const int
is_letter_or_digit(const char c)
{
    return (is_letter(c) || is_digit(c));
}

const int
is_whitespace(const char c)
{
    return (
        c == 32 ||
        c == 9 ||
        c == 10
        );
}

const int
is_sym(const char c)
{
    int i = 0;
    for (; i < 2; i++)
        if (c == CX_SYM[i])
            return 1;
    return 0;
}
