#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

int DEBUG = 0;

void
slog(char *msg)
{
    if (DEBUG) {
        printf("%s", msg);
    }
}

void
chlog(char msg)
{
    if (DEBUG) {
        printf("%c", msg);
    }
}

void
ilog(int msg)
{
    if (DEBUG) {
        printf("%d", msg);
    }
}

#endif /* DEBUG_H */
