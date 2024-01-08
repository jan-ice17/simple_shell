#include "simple_shell.h"

void exec_a_command(char *user_cmd)
{
    pid_t my_pid = fork();

    if (my_pid == -1)
    {
        perror(":( Fork Failed ");
        exit(EXIT_FAILURE);
    }

    if (my_pid == 0) /* Child Process */
    {
        char **args = malloc(sizeof(char *) * 2);
        if (args == NULL)
        {
            perror(":( Memory Allocation Failed");
            exit(EXIT_FAILURE);
        }

        args[0] = user_cmd;
        args[1] = NULL;

        execvp(args[0], args);

        /* If execvp fails, print an error message */
        perror(":( Execvp Failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        /* Parent process */
        wait(NULL);
    }
}

