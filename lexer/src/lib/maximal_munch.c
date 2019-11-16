#include <dfa.h>

// TODO : Change according to new design
typedef struct temp_tk {
} TOKEN;

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
            //TOKEN *tk = create_token(state, reverse_str(consumed)); // TODO : error handling
            TOKEN *tk = 0x0;
            return tk;
        } else return 0x0;
    } else
    {
        *offset += 1;
        int next_state = transition(state, input[0]);
        consumed = add_char(consumed, input[0], 1);
        return munch_one(input, offset, next_state, consumed);
    }
}

TOKEN **
munch_all(char *input, unsigned long *offset, TOKEN **accum, unsigned long accumsz)
{
    if (input == 0x0)
    {
        reverse_tkarr(accum, accumsz);
        return accum;
    } else
    {
        char *consumed = malloc(4 *sizeof(char));
        TOKEN *munched = munch_one(input, offset, START, consumed);
        add_tkarr(accum, accumsz, munched, 1);
        return munch_all(input, offset, accum, accumsz + 1);
    }
}

TOKEN **
maximal_munch_temp(char *input)
{
    TOKEN **accum = malloc(sizeof(TOKEN *));
    unsigned long offset = 0;
    return munch_all(input, &offset, accum, 0);
}
