#include <str_helper.h>
#include <scan.h>

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
LL_CHAR* munch(LL_CHAR* buffer_head, LL_CHAR* state_head);

// Maximal munch over a linked list
state iterative_munch(LL_CHAR *chars);

// TODO : Confusing :(
// This calls `munch` on a string to get words out
stateful_token *maximal_munch(const stateless_token *tk);

// Helpers
void pretty_state(state s);

