#include <stdio.h>
#include <file_io_helpers.h>
#include <dfa.h>
// #include <debug.h> // TODO : Fix include problems

// ORDER OF OPERATIONS:
// 1. You read a string representing the source code
// 2. You scan it to get stateless tokens, IE tokens that are NOT part of a DFA
// 3. You munch it to get a DFA pass and get stateful tokens.
// 4. Print out stateful token on each line
// 5. Exit

int extern DEBUG;

int
main(int argc, char *argv[])
{
    if (argc < 2)
    {
        perror("Usage: lexer <C source file>\n");
        exit(EXIT_FAILURE);
    }

    // TODO :Debugging switch
    DEBUG = 1;

    printf("Reading C input...\n");
    int in_sz;
    char *raw = read_file(argv[1], &in_sz);

    printf("Creating a linked-list of C input...\n");
    LL_CHAR *raw_ll = string_to_ll(raw);
    
    printf("Running maximal-munch on the linked-list of characters...\n");
    int final_state = iterative_munch(raw_ll);
    printf("Final state of maximal-munch: %d\n", final_state);
    
    // TODO : Free LL
    free(raw);
	return 0;
}
