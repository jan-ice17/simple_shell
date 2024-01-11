#include "jantee_shell.h"

void jan_display_prompt(void) {
    write(STDOUT_FILENO, "JANTEE/$ ", 9);
}

char *jan_read_input(void) {
    char *input = NULL;
    ssize_t read_bytes;
    size_t len = 0;

    jan_display_prompt();
    read_bytes = getline(&input, &len, stdin);

    if (read_bytes == -1) {
        if (feof(stdin)) {
            free(input);
            return NULL;
        } else {
            perror(progr_name);
            exit(EXIT_FAILURE);
        }
    }

    if (input[read_bytes - 1] == '\n') {
        input[read_bytes - 1] = '\0';
    }

    return input;
}
