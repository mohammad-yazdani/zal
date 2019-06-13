#include <stdio.h>
#include <token.h>

int
main()
{
    printf("Zal Scanner!\n");
    int size;
    char **tokens = tokenize(stdin, &size);
    
    split_test(tokens, size);

    free(tokens);
	return 0;
}
