// This file defines the scanner's data-structures and different passes
// It requires token.h to produce data-structures understandable by the parser

#include <stdlib.h>
#include <token.h>

typedef struct scanned_word {
    char *val;
    size_t len;
} WORD;

// TODO : State: these functions allocate objects/arrays
int split_words(char *in, WORD **out);
int tokenize(WORD **in, stateless_token **out); 

