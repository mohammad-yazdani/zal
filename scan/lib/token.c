#include <token.h>

// TODO : Implement error handling

int
is_empty(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

char **
tokenize(const char *raw, int size, int *num_tk)
{
	int token_count = 0, i = 0;
	int token_meta_sz = 4;
    int tk_idx = 0, tk_char_idx = 0, empty = 0;

	int *token_meta = malloc(token_meta_sz * sizeof(int)); // 4 tokens min

    for (i = 0; i < size; i++)
    {
        if (token_meta_sz < (token_count * 2))
        {
            token_meta_sz = token_meta_sz * 2;
            token_meta = realloc(token_meta, token_meta_sz * sizeof(int));
        }
        if (is_empty(raw[i]))
        {
            if (empty) continue;
            empty = 1;
            token_count += 1;
        } else
        {
            empty = 0;
            token_meta[token_count] += 1;
        }
    }

    char **token_buff = malloc(token_count * sizeof(char *));
    i = 0;
    for (; i < token_count; i++)
    {
        int tksz = token_meta[i];
        token_buff[i] = malloc((tksz + 1) * sizeof(char));
    }
    free(token_meta);

    empty = 0;
	for (i = 0; i < size; i++)
	{
		if (is_empty(raw[i]))
		{
		    if (empty) continue;
		    empty = 1;
			token_buff[tk_idx][tk_char_idx] = '\0';
			tk_idx += 1;
			tk_char_idx = 0;
		} else
		{
		    empty = 0;
			token_buff[tk_idx][tk_char_idx] = raw[i];
			tk_char_idx += 1;
		}
	}

	*num_tk = token_count;
	return token_buff;
}

void
destroy_tkarr(char **tk, int size)
{
    int i = 0;
    for (; i < size; i++)
        free(tk[i]);
}

void
split_test(char **tk_buff, int tk_sz)
{
	int i = 0;
	for (; i < tk_sz; i++)
	{
		printf("%s\n", tk_buff[i]);
	}
}

void
reverse_tkarr(TOKEN **tkarr, unsigned long size)
{
    int i = 0;
    for (; i < (size / 2); i++)
    {
        TOKEN *right = tkarr[size - i - 1];
        TOKEN *left = tkarr[i];
        tkarr[i] = right;
        tkarr[size - i - 1] = left;
    }
}

void
add_tkarr(TOKEN **tkarr, unsigned long size, TOKEN *tk, int prepend)
{
    tkarr = realloc(tkarr, (size + 1) * sizeof(TOKEN *));

    if (prepend)
    {
        int i = size;
        for (; i > 0; i--)
        {
            tkarr[i] = tkarr[i - 1];
        }
        tkarr[0] = tk;

        size += 1;
    } else
    {
        tkarr[size] = tk;
        size += 1;
    }
}

TOKEN *
create_token(int state, const char *val)
{
	return NULL;
}

