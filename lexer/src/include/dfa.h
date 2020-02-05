#include <str_helper.h>
#include <linked_list.h>
#include <stream.h>
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

// This basically takes a char with prev state and sees if what you're doing makes sense.
LLNODE* munch(STREAM *buffer, LLNODE *state_head);

// Maximal munch over a linked list
LLNODE* iterative_munch(LLNODE *chars);

// TODO : Confusing :(
// This calls `munch` on a string to get words out
// stateful_token *maximal_munch(const stateless_token *tk);

// Helpers
const char* pretty_state(state s);

// TODO : TEMPORARY
void slog_wrapper(const char *msg);

