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
    if (argc == 3)
    {
        // TODO : Pass 'd' as second arg to turn on debug
        if (argv[2][0] == 'd') DEBUG = 1;
    }

    slog_wrapper("Reading C input...\n");
    int in_sz;
    char *raw = read_file(argv[1], &in_sz);

    slog_wrapper("Creating a linked-list of C input...\n");
    LLNODE *raw_ll = string_to_ll(raw);
    
    slog_wrapper("Running maximal-munch on the linked-list of characters...\n");
    LLNODE *states = iterative_munch(raw_ll);
    slog_wrapper("Lex done!\n\n");

    LLNODE *curr = states;
    while (curr != NULL)
    {
        TOKEN *currtk = (TOKEN *)(curr->data);
        if (currtk->meta != START) printf("%s\n", pretty_state(currtk->meta));
        curr = curr->next;
    }

    curr = identify(curr);

    // TODO : Free LL
    free(raw);
	return 0;
}
