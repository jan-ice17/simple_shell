#include "jantee_shell.h"

/**
 * jan_exec_command - Execute a command
 * @args: Array of command arguments
 */
void jan_exec_command(char **args)
{
    pid_t jan_pid = fork();

    if (jan_pid == -1)
    {
        perror(progr_name);
        exit(EXIT_FAILURE);
    }

    if (jan_pid == 0)
    {
        if (execve(args[0], args, NULL) == -1)
        {
            perror(progr_name);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(jan_pid, NULL, 0);
    }
}

/**
 * free_mem - Free memory allocated for command arguments
 * @args: Array of command arguments
 */
void free_mem(char **args)
{
    char **temp = args;
    while (*temp != NULL)
    {
        free(*temp);
        temp++;
    }
    free(args);
}