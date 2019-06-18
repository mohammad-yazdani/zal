//
// Created by yazda on 6/17/2019.
//

#include <maximal_munch.h>


// TODO : consumed defaults to empty. During the  recursive calls it
// TODO : is populated using realloc
// TODO : input is from a tokenize call
TOKEN
munch_one(const char *input, unsigned long *offset, int state, char **consumed)
{
    if (empty_str(input) || transition(state, input[*offset]))
        if (is_in_alphabet(state))
        {
            // TODO : Here we create a TOKEN, has to co with consumed stuff

        }
}

TOKEN **
maximal_munch(const char **input)
{
    return NULL;
}
