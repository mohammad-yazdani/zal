//
// Created by yazda on 6/17/2019.
//

#include "str_helper.h"

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
