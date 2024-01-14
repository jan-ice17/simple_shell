#include "shell.h"

/**
 * Executes a program specified by the file path with the given arguments.
 * 
 * @file_path: The path to the program file.
 * @args: The arguments to be passed to the program.
 * @program_name: The name of the program.
 */

void _execute(const char *file_path, char **const args, const char *program_name) {
    pid_t jantee_pid;
    char *full_path = NULL;

    if (file_path[0] != '/') {
        char *path_env = getenv("PATH");
        char *path_copy = _strdup(path_env);
        char *token = _strtok(path_copy, ":");

        while (token != NULL && full_path == NULL) {
            full_path = malloc(_strlen(token) + _strlen(file_path) + 2);
            _strcpy(full_path, token);
            _strcat(full_path, "/");
            _strcat(full_path, file_path);

            if (access(full_path, X_OK) == -1) {
                free(full_path);
                full_path = NULL;
            }

            token = _strtok(NULL, ":");
        }

        free(path_copy);

        if (full_path == NULL) {
            perror(program_name);
            return;
        }

        file_path = full_path;
    } else if (access(file_path, X_OK) == -1) {
        perror(program_name);
        return;
    }

    jantee_pid = fork();

    if (jantee_pid == -1) {
        perror(program_name);
        exit(EXIT_FAILURE);
    }

    if (jantee_pid == 0) {
        if (execve(file_path, args, NULL) == -1) {  
            perror(program_name);
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(jantee_pid, NULL, 0);
    }

    free(full_path);
}