#include <stdio.h>
#include <stdlib.h>

typedef struct min_c_token {
	int meta;
	char *value;
} Token;

char **
tokenize(FILE *read_fd, int *size);

void
split_test(char **tk_buff, int tk_sz);
