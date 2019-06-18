//
// Created by yazda on 6/17/2019.
//

#include <maximal_munch.h>


// TODO : consumed defaults to empty. During the  recursive calls it
// TODO : is populated using realloc
// TODO : input is from a tokenize call
TOKEN *
munch_one(const char *input, unsigned long *offset, int state, char *consumed)
{
    if (empty_str(input) || transition(state, input[*offset]) == -1)
    {
        if (is_in_alphabet(state))
        {
            // TODO : Here we create a TOKEN, has to co with consumed stuff
            TOKEN *tk = create_token(state, reverse_str(consumed)); // TODO : error handling
            return tk;
        } else return NULL;
    } else
    {
        *offset += 1;
        int next_state = transition(state, input[0]);
        consumed = add_char(consumed, input[0], 1);
        return munch_one(input, offset, next_state, consumed);
    }
}

TOKEN **
munch_all(char *input, unsigned long *offset, TOKEN **accum)
{
    if (input == NULL) // TODO : Reverse accum
    {

    } else
    {
        char *consumed = malloc(4 *sizeof(char));
        TOKEN *munched = munch_one(input, offset, START, consumed);
        // TODO : Pre-pend munched to accum
        return munch_all(input, offset, accum);
    }
}

TOKEN **
maximal_munch(char *input)
{
    TOKEN **accum = malloc(sizeof(TOKEN *));
    unsigned long offset = 0;
    return munch_all(input, &offset, accum);
}
