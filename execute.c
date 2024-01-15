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

    /* Return if file_path is NULL */
    if (file_path == NULL) {
        return;
    }

    /* If file_path is not an absolute path or a relative path from the current directory */
    if (file_path[0] != '/' && _strncmp(file_path, "./", 2) != 0 && _strncmp(file_path, "../", 3) != 0)  {
        char *path_env = getenv("PATH");
        char *path_copy = _strdup(path_env);
        char *token = _strtok(path_copy, ":");

        /* Loop through each directory in the PATH environment variable */
        while (token != NULL && full_path == NULL) {
            /* Allocate memory for the full path of the file */
            full_path = malloc(_strlen(token) + _strlen(file_path) + 2);
            _strcpy(full_path, token);
            _strcat(full_path, "/");
            _strcat(full_path, file_path);

            /* If the file does not exist or is not executable, free the memory and set full_path to NULL */
            if (access(full_path, X_OK) == -1) {
                free(full_path);
                full_path = NULL;
            }

            token = _strtok(NULL, ":");
        }

        free(path_copy);

        /* If the file was not found in any directory in the PATH, print an error message and return */
        if (full_path == NULL) {
            perror(program_name);
            return;
        }

        file_path = full_path;
    } 
    /* If the file_path is an absolute path or a relative path from the current directory, check if the file exists */
    else if (access(file_path, X_OK) == -1) {
        perror(program_name);
        return;
    }

    /* Create a new process */
    jantee_pid = fork();

    /* If fork failed, print an error message and exit */
    if (jantee_pid == -1) {
        perror(program_name);
        exit(EXIT_FAILURE);
    }

    /* If this is the child process, execute the file */
    if (jantee_pid == 0) {
        if (execve(file_path, args, NULL) == -1) {  
            perror(program_name);
            exit(EXIT_FAILURE);
        }
    } 
    /* If this is the parent process, wait for the child process to finish */
    else {
        waitpid(jantee_pid, NULL, 0);
    }

    /* Free the memory allocated for full_path */
    free(full_path);
}