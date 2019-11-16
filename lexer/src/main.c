#include <stdio.h>
#include <scan.h>
#include <file_io_helpers.h>

// ORDER OF OPERATIONS:
// 1. You read a string representing the source code
// 2. You scan it to get stateless tokens, IE tokens that are NOT part of a DFA
// 3. You munch it to get a DFA pass and get stateful tokens.
// 4. Print out stateful token on each line
// 5. Exit

int
main(int argc, char *argv[])
{
    if (argc < 2)
    {
        perror("Usage: lexer <C source file>\n");
        exit(EXIT_FAILURE);
    }
    int in_sz;
    char *raw = read_file(argv[1], &in_sz);

    LL_CHAR **word_ll;
    if (split_words(raw, word_ll)) {
        return 1;
    }
    
    // TODO : Simple testing splitter
    while ((*word_ll)->next)
    {
        if ((*word_ll)->val != '\0') printf("%c", (*word_ll)->val);
        else printf("\n");
        *word_ll = (*word_ll)->next; 
    }
    printf("\n");
    
    free(raw);
	return 0;
}
