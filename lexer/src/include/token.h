#include <stdlib.h>
#include <linked_list.h>

// This header defines the data-structures describing the tokens of MIN_C.

typedef struct token {
    LLNODE *end;
    int meta;
} TOKEN;

TOKEN *create_token(LLNODE *end, int meta);
void destroy_token(TOKEN *tk);

