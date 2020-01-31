#include <stream.h>

// TODO : Calls malloc
STREAM *
create_stream(LL_CHAR* head)
{
    STREAM *newstream = malloc(sizeof(STREAM));
    newstream->head = head;
    newstream->cursor = head;
    return newstream;
}

int
next(STREAM *s)
{
    // TODO : Check for NULL
    if (s->cursor->next == NULL) return 0;
    s->cursor = s->cursor->next;
    return 1;
}

int
prev(STREAM *s)
{
    // TODO : Check for NULL
    if (s->cursor->prev == NULL) return 0;
    s->cursor = s->cursor->prev;
    return 1;
}

char
val(STREAM *s)
{
    return s->cursor->val;
}
