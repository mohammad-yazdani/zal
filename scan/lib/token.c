#include <token.h>

// TODO : Implement error handling

char **
tokenize(FILE *read_fd, int *size)
{
	int readchars = 0, token_chars = 0, empty_row = 0, token_count = 0;
	int buff_sz = 16, token_meta_sz = 4;
	char *buff = malloc(buff_sz * sizeof(char)); // 16 chars min
	int *token_meta = malloc(token_meta_sz * sizeof(int)); // 4 tokens min

	char c;

	while(EOF != (c = fgetc(read_fd)))
	{
		if (readchars > (buff_sz / 2))
		{
			buff_sz *= 2;
			buff = realloc(buff, buff_sz * sizeof(char));
		}
		if (token_count > (token_meta_sz / 2))
		{
			token_meta_sz *= 2;
			token_meta = realloc(token_meta, token_meta_sz * sizeof(int));
		}
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (empty_row)
				continue;
			else
			{
				token_meta[token_count] = token_chars;
				buff[readchars] = '\n';
				token_chars = 0;
				empty_row = 1;
				readchars += 1;
				token_count += 1;
			}
		}
		else
		{
			empty_row = 0;
			token_chars += 1;
			buff[readchars] = c;
			readchars += 1;
		}
	}


	char **token_buff = malloc(token_count * sizeof(char *));
	int i = 0;
	for (; i < token_count; i++)
	{
		int tksz = token_meta[i];
		token_buff[i] = malloc((tksz + 1) * sizeof(char));
	}
	int tk_idx = 0, tk_char_idx = 0;
	for (i = 0; i < readchars; i++)
	{
		if (buff[i] == '\n')
		{
			token_buff[tk_idx][tk_char_idx] = '\0';
			tk_idx += 1;
			tk_char_idx = 0;
		} else
		{
			token_buff[tk_idx][tk_char_idx] = buff[i];
			tk_char_idx += 1;
		}
	}

	free(buff);
	free(token_meta);

	*size = token_count;
	return token_buff;
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
