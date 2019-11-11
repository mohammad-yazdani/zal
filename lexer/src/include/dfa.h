#include <str_helper.h>
#include <token.h>

typedef enum STATE {
    START,
    UNDEFINED,
    INVALID,
    SPACE,
    TAB,
    NEWLINE,
    COMMENT,
    WHITESPACE,
    DEF,
    NUM,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    RETURN,
    IF,
    ELSE,
    WHILE,
    PRINTLN,
    MAIN,
    BECOMES,
    INT,
    EQ,
    NE,
    LT,
    GT,
    LE,
    GE,
    PLUS,
    MINUS,
    STAR,
    SLASH,
    PCT,
    COMMA,
    SEMI,
    NEW,
    DELETE,
    LBRACK,
    RBRACK,
    AMP, 
    NULLL,
    ZERO,
    BANG
} state;

typedef struct STATEFUL_TOKEN {
    const char *tk_val;
    const state tk_state;
} stateful_token;

// This basically takes a char with prev state and sees if what you're doing makes sense.
state munch(state prev, char in_char);

// This calls `munch` on a string to get words out
stateful_token *maximal_munch(const stateless_token *tk);

