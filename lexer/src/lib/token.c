#include <token.h>

TOKEN *create_token(LLNODE *end, int meta)
{
    TOKEN *newtk = malloc(sizeof(TOKEN));
    newtk->end = end;
    newtk->meta = meta;
    return newtk;
}

void destroy_token(TOKEN *tk)
{
    free(tk);
}

