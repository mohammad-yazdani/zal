#include <stdlib.h>
#include <linked_list.h>

// This header defines the data-structures describing the tokens of MIN_C.

typedef enum LANG_TOKENS_IDX {
    idx_ID, idx_NUM, idx_LPAREN, idx_RPAREN, idx_LBRACE, idx_RBRACE, idx_RETURN, idx_IF,
    idx_ELSE, idx_WHILE, idx_MAIN, idx_BECOMES, idx_INT, idx_EQ, idx_NE,
    idx_LT, idx_GT, idx_LE, idx_GE, idx_PLUS, idx_MINUS, idx_STAR, idx_SLASH, idx_PCT,
     idx_COMMA, idx_SEMI, idx_NEW, idx_DELETE, idx_LBRACK, idx_RBRACK, idx_AMP, idx_NULL, idx_ZERO
} token_idx;

static const char *
LANG_TOKENS[] = {"ID", "NUM", "LPAREN", "RPAREN","LBRACE","RBRACE","RETURN","IF",
        "ELSE","WHILE","MAIN","BECOMES","INT","EQ","NE","LT","GT","LE","GE","PLUS","MINUS",
        "STAR","SLASH","PCT","COMMA","SEMI","NEW","DELETE","LBRACK","RBRACK","AMP","NULL", "ZERO"};

typedef struct token {
    LLNODE *end;
    int idx;
    int meta;
} TOKEN;

TOKEN *create_token(LLNODE *end, int meta);
void destroy_token(TOKEN *tk);
LLNODE *identify(LLNODE *headtk);

