#include <scan.h>

typedef struct stream
{
    const LL_CHAR *head;
    LL_CHAR *cursor;
} STREAM;

STREAM *create_stream(const LL_CHAR* head);
void next(STREAM *s);
void prev(STREAM *s);
char val(STREAM *s);
