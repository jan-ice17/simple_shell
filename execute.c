#include "shell.h"

extern char **environ;

/**
 * Get the full path of a file.
 * @param file_path: The file to get the full path of.
 * @return The full path of the file.
 */
char *get_full_path(const char *file_path) {
    char *path_env = getenv("PATH");
    char *path_copy = _strdup(path_env);
    char *token = _strtok(path_copy, ":");
    char *full_path = NULL;

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
    return full_path;
}


/**
 * Executes a file with the given file path and arguments.
 * 
 * @param file_path The path of the file to be executed.
 * @param args The arguments to be passed to the executed file.
 * @param program_name The name of the program executing the file.
 */
void execute_file(const char *file_path, char **const args, const char *program_name) {
    pid_t jantee_pid = fork();

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
}


/**
 * Executes a file with the given file path and arguments.
 *
 * @param file_path The path of the file to be executed.
 * @param args The arguments to be passed to the executed file.
 * @param program_name The name of the program executing the file.
 */
void _execute(const char *file_path, char **const args, const char *program_name) {
    char *full_path = NULL;
    char **env;

    if (file_path == NULL) {
        return;
    }
    
    if (_strcmp(file_path, "exit") == 0) {
        int status = EXIT_SUCCESS;
        if (args[1] != NULL) {
            status = _atoi(args[1]);
        }
        exit(status);
    }

    if (_strcmp(file_path, "env") == 0) {
        for (env = environ; *env != NULL; env++) {
            _printf(*env);
            _printf("\n");
        }
        return;
    }

    if (file_path[0] != '/' && _strncmp(file_path, "./", 2) != 0 && _strncmp(file_path, "../", 3) != 0)  {
        full_path = get_full_path(file_path);
        if (full_path == NULL) {
            perror(program_name);
            return;
        }
        file_path = full_path;
    } else if (access(file_path, X_OK) == -1) {
        perror(program_name);
        return;
    }

    execute_file(file_path, args, program_name);

    if (full_path != NULL) {
        free(full_path);
    }
}