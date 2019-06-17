#include <stdio.h>
#include <stdlib.h>

typedef struct min_c_token {
	int meta;
	char *value;
} TOKEN;

// TODO : Re-implement functions to respect tk type

TOKEN **tokenize(const char *raw, int size, int *num_tk);

void destroy_tkarr(TOKEN **tk, int size);

void split_test(TOKEN **tk_buff, int tk_sz);
