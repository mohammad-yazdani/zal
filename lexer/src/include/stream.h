#include <linked_list.h>

typedef struct stream
{
    LLNODE *head;
    LLNODE *cursor;
} STREAM;

STREAM *create_stream(LLNODE* head);
int next(STREAM *s);
int prev(STREAM *s);
char val(STREAM *s);
