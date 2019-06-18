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

unsigned long
str_len(const char *arr)
{
    int i = 0;
    while (arr[i] != '\0')
        i++;
    return i;
}

int
empty_str(const char *arr)
{
    return (str_len(arr) == 0);
}
char *
reverse_str(const char *str)
{
    unsigned long len = str_len(str);
    char *rev = malloc((len + 1) *sizeof(char));
    rev[len] = '\0';
    int i = 0;
    for (; i < (len / 2); i++)
    {
        rev[i] = str[len - i - 1];
        rev[len - i - 1] = str[i];
    }
    return rev;
}

char *
add_char(char *str, char c, int prepend)
{
    int len = str_len(str);
    str = realloc(str, (len + 2) *sizeof(char));
    str[len + 1] = '\0';
    len += 1;

    if (prepend)
    {
        int i = len - 1;
        for (; i > 0; i--)
        {
            str[i] = str[i - 1];
        }
        str[0] = c;
    } else
        str[len - 1] = c;

    return str;
}
