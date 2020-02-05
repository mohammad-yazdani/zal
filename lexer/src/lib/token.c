#include <token.h>
#include <stdio.h> // TODO : Temp

TOKEN *create_token(LLNODE *end, int meta)
{
    TOKEN *newtk = malloc(sizeof(TOKEN));
    newtk->end = end;
    newtk->idx = -1;
    newtk->meta = meta;
    return newtk;
}

void destroy_token(TOKEN *tk)
{
    free(tk);
}

// TODO : Bad algorithm, modify dfa.c
LLNODE *
identify(LLNODE *headtk)
{
    LLNODE *curr = headtk;
    LLNODE *next = curr->next;
    while(curr && next)
    {
        TOKEN *curr_tk = (TOKEN *)(curr->data);
        TOKEN * next_tk = (TOKEN *)(next->data);
        
        LLNODE *curr_tk_str = curr_tk->end;
        LLNODE *next_tk_str = next_tk->end;
        while(curr_tk_str != next_tk_str)
        {
            printf("%c", *(char *)(curr_tk_str->data));
            curr_tk_str = curr_tk_str->next;
        }
        printf("\n");

        curr = next;
        next = next->next;
    }
    return NULL;
}
