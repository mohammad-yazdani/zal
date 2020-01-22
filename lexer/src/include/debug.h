#include <stdio.h>

extern int DEBUG;

void
slog(char *msg)
{
    printf("%s", msg);
}

void
chlog(char msg)
{
    printf("%c", msg);
}

void
ilog(int msg)
{
    printf("%d", msg);
}

