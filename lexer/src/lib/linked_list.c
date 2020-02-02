#include <linked_list.h>
#include <string.h>
#include <stdlib.h>

LLNODE *
create_LLNODE(void *data)
{
    LLNODE *newnode = malloc(sizeof(LLNODE));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

LLNODE *
LL_push(LLNODE *head, void* data)
{
    LLNODE *new_l = create_LLNODE(data);
    LLNODE *old_next = (head->next) ? head->next : NULL;
    head->next = new_l;
    new_l->prev = head;
    new_l->next = old_next;

    return new_l;
}

LLNODE *
string_to_ll(char *str)
{
    LLNODE *head = create_LLNODE(&str[0]);
    LLNODE *prepush_head = head;

    unsigned int len = strlen(str);
    unsigned int  i = 1;
    for(; i < len; i++)
    {
        head = LL_push(head, &str[i]);
    }

    return prepush_head;
}
