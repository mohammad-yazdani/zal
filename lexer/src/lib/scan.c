#include <scan.h>
#include <string.h>
#include <stdlib.h>

int
is_empty(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

LL_CHAR *
create_LL_char(char val)
{
    LL_CHAR *new_char = malloc(sizeof(LL_CHAR));
    new_char->val = val;
    new_char->prev = NULL;
    new_char->next = NULL;
    return new_char;
}

LL_CHAR *
LL_push(LL_CHAR *head, char new_val)
{
    LL_CHAR *new_l = create_LL_char(new_val);
    LL_CHAR *old_next = (head->next) ? head->next : NULL;
    head->next = new_l;
    new_l->prev = head;
    new_l->next = old_next;

    return new_l;
}

LL_CHAR *
string_to_ll(char *str)
{
    LL_CHAR *head = create_LL_char(str[0]);
    LL_CHAR *prepush_head = head;

    unsigned int len = strlen(str);
    unsigned int  i = 1;
    for(; i < len; i++)
    {
        head = LL_push(head, str[i]);
    }

    return prepush_head;
}
