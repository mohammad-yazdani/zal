#include <stdio.h>
#include <token.h>
#include <file_io/file_io_helpers.h>

int
main(int argc, char *argv[])
{
    if (argc < 2)
    {
        perror("Usage: ./scan <c source file>\n");
        exit(EXIT_FAILURE);
    }
    int in_sz;
    char *raw = read_file(argv[1], &in_sz);

    int size;
    char **tokens = tokenize(raw, in_sz, &size);
    
    split_test(tokens, size);

    free(tokens);
	return 0;
}
