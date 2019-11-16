// This file defines the scanner's data-structures and different passes
// It requires token.h to produce data-structures understandable by the parser

#include <stdlib.h>
#include <token.h>

struct linked_list_scanned_char;
typedef struct linked_list_scanned_char LL_CHAR;

typedef struct linked_list_scanned_char {
    char val;
    LL_CHAR *next;
} LL_CHAR;

LL_CHAR *create_LL_char(char val);
LL_CHAR *LL_push(LL_CHAR *head, char val); // TODO : To be re-written later as part of the linked list

// TODO : State: these functions allocate objects/arrays
int split_words(char *in, LL_CHAR **out); // TODO : temp: read func impl for docs
int tokenize(LL_CHAR **in, stateless_token **out); 

