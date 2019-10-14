#include <stdio.h>
#include <token.h>
#include <file_io_helpers.h>

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

    // TODO : DEBUG
    printf("%s\n", raw);

    int size;
    char **tokens = tokenize(raw, in_sz, &size);
    
    split_test(tokens, size);

    destroy_tkarr(tokens, size);
    free(tokens);
    free(raw);
	return 0;
}
