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
    return new_char;
}

LL_CHAR *
LL_push(LL_CHAR *head, char new_val)
{
    head->next = create_LL_char(new_val);
    return head->next;
}

int
split_words(char *in, LL_CHAR **out)
{
    // Simple ops to separate words out of white space
    size_t len = strlen(in);
    if (len < 1) return 1; 

    LL_CHAR *head = create_LL_char(in[0]);
    LL_CHAR *output_head = head;

    unsigned int i = 1;
    for (; i < len; i++)
    {
        if (is_empty(in[i]))
        {
            if (head->val != '\0') head = LL_push(head, '\0'); 
        }
        else
        {
            head = LL_push(head, in[i]);
        }
    }
    *out = output_head;

    return 0;
}

int
tokenize(LL_CHAR **in, stateless_token **out)
{
    // TODO : Extract tokens out of the words based on lang standards
    return 0;
}

