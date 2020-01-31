#include <scan.h>

typedef struct stream
{
    LL_CHAR *head;
    LL_CHAR *cursor;
} STREAM;

STREAM *create_stream(LL_CHAR* head);
int next(STREAM *s);
int prev(STREAM *s);
char val(STREAM *s);
