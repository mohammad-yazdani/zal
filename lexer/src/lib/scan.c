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

int
split_words(char *in, LL_CHAR **out)
{
    // Simple ops to separate words out of white space
    size_t len = strlen(in);
    if (len < 1) return 1;
    *out = create_LL_char(in[0]);

    LL_CHAR *head = *out;
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

    return 0;
}




/*>>>>>>>>>>>>>>>>>>>>>>>>> TEMP <<<<<<<<<<<<<<<<<<<<<<<<<<<*/

// TODO : Use this temporarily for symbol crap
// TODO : Integrate this helper function properly later
int
is_sym_temp(char val)
{
    int sum = 0;
    sum += val == ';';
    sum += (val == '[' || val == ']');
    sum += (val == '(' || val == ')');
    sum += (val == '{' || val == '}');
    sum += val == ',';
    sum += val == '=';
    sum += val == '+';
    sum += val == '-';
    sum += val == '*';
    sum += val == '/';
    return sum;
}
// TODO : put in docs:
// TODO : this function either has to mutate the input linked list
// TODO : or copy it
int
tokenize(LL_CHAR *in, stateless_token **out)
{
    // TODO : Extract tokens out of the words based on lang standards
    
    // TODO : Make the human brain happy here
    LL_CHAR *head = in;
    while (head)
    {
        int symbol = is_sym_temp(head->val);
        if (symbol != 0)
        {
            // TODO : This should be implemented in linked list API later
            // TODO : The language REQUIRES space after `;`
            LL_CHAR *prev = head->prev;
            
            if (head->prev && head->prev->val != '\0') {
                // prev->\0
                LL_CHAR *l0 = LL_push(prev, '\0');
            }
            if (head->next && head->next->val != '\0') {
                // head->\0
                LL_CHAR *r0 = LL_push(head, '\0');
            }
        }
        head = head->next;
    }

    return 0;
}

