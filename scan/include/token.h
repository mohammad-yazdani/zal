#include <stdio.h>
#include <stdlib.h>

typedef struct min_c_token {
	int meta;
	char *value;
} Token;

char **
tokenize(const char *raw, int size, int *num_tk);

void
destroy_tkarr(char **tk, int size);

void
split_test(char **tk_buff, int tk_sz);
