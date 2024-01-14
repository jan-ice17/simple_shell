#include "shell.h"

/**
 * Display the shell prompt.
 */
void display_prompt() {
    if (isatty(STDIN_FILENO)) {
        _printf("(JANTEE)$ "); 
        fflush(stdout);
    }
}

/**
 * Split the command into tokens.
 * @param command: The string to be split.
 * @return An array of tokens.
 */
char **split_string(char *command) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    if (!tokens) {
        _printf("Allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = _strtok(command, " \n");
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                _printf("Allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = _strtok(NULL, " \n");
    }
    tokens[position] = NULL;
    return tokens;
}

/**
 * Read a command from the user.
 * @return The command read from the user.
 */
char *read_command() {
    char *line = NULL;
    size_t bufsize = 0;
    if (getline(&line, &bufsize, stdin) == -1) {
        if (isatty(STDIN_FILENO)) {
            _printf("\n");
        }
        free(line);
        exit(EXIT_SUCCESS);
    }
    return line;
}