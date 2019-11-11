#include <stdio.h>
#include <stdlib.h>

// This header defines the data-structures describing the tokens of MIN_C.

typedef enum TOKEN_TYPE {
    KEYWORD,
    ID,
    CONST,
    STRING,
    SYMBOL,
    OPERATOR
} token_type;

typedef struct STATELESS_TOKEN {
	const token_type tk_type;
	const char *tk_val;
} stateless_token;

stateless_token *create_token(const char *val, token_type type);
void destroy_token(stateless_token *tk);

