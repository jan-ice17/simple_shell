#include "shell.h"


/**
 * Executes a program specified by the file path with the given arguments.
 * 
 * @file_path: The path to the program file.
 * @args: The arguments to be passed to the program.
 * @program_name: The name of the program.
 */
void _execute(const char *file_path, char **const args, const char *program_name) {
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


