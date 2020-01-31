// This file defines the scanner's data-structures and different passes
// It requires token.h to produce data-structures understandable by the parser

#include <stdlib.h>

typedef struct linked_list_scanned_char {
    char val;
    struct linked_list_scanned_char *prev;
    struct linked_list_scanned_char *next;
} LL_CHAR;

LL_CHAR *create_LL_char(char val);
// TODO : To be re-written later as part of the linked list
LL_CHAR *LL_push(LL_CHAR *head, char val); 

// Helper
// Allocs mem
LL_CHAR *string_to_ll(char *str);

