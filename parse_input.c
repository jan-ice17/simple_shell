#include "shell.h"

/**
 * Display prompt "(JANTEE)$ " if input coming from terminal.
 */
void display_prompt() {
    if (isatty(STDIN_FILENO)) {
        _printf("(JANTEE)$ "); 
        fflush(stdout);
    }
}

/**
 * Split string into array of tokens.
 *
 * @command: The string to be split.
 * @return An array of tokens.
 */
char **split_string(char *command) {
    char **args = malloc(64 * sizeof(char *));
    char *my_tok;
    int i = 0;

    my_tok = _strtok(command, " \n");
    while (my_tok != NULL) {
        args[i] = my_tok;
        i++;
        my_tok = _strtok(NULL, " \n");
    }
    args[i] = NULL;

    return args;
}

/**
 * Read command from user.
 * 
 * @return Command entered by the user.
 */
char *read_command() {
    char *comm = NULL;
    size_t buf_size = 0;

    if (_getline(&comm, &buf_size, 0) == 0) {
        /*Handling eof (Ctrl+D)*/ 
        if (isatty(STDIN_FILENO)) {
            _printf("\n");
        }
        free(comm);
        exit(EXIT_SUCCESS);
    }

    return comm;
}