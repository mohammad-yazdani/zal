// This file defines the scanner's data-structures and different passes
// It requires token.h to produce data-structures understandable by the parser

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct linked_list {
    void *data;
    struct linked_list *prev;
    struct linked_list *next;
} LLNODE;

LLNODE *create_LLNODE(void *data);
// TODO : To be re-written later as part of the linked list
LLNODE *LL_push(LLNODE *head, void* data); 

// Helper
// Allocs mem
LLNODE *string_to_ll(char *str);


#endif

