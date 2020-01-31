#include <stream.h>

// TODO : Calls malloc
STREAM *
create_stream(const LL_CHAR* head)
{
    STREAM *newstream = malloc(sizeof(STREAM));
    newstream->head = head;
    newstream->cursor = head;
    return newstream;
}

void
next(STREAM *s)
{
    // TODO : Check for NULL
    s->cursor = s->cursor->next;
}

void
prev(STREAM *s)
{
    // TODO : Check for NULL
    s->cursor = s->cursor->prev;
}

char
val(STREAM *s)
{
    return s->cursor->val;
}
