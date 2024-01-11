#include "jantee_shell.h"

char *progr_name; 

/**
 * main - Entry point for the shell program.
 *
 * @argc: The number of command line arguments.
 * @argv: An array of strings containing the command line arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
    char *input;
    char **args;
    progr_name = argv[0];
    
    while (1)
    {
        input = jan_read_input();

        if (input == NULL)
        {
            argc = 1;
            write(STDOUT_FILENO, "\n", argc);
            break;
        }

        args = parse_input(input);
        if (args[0] != NULL)
        {
            jan_exec_command(args);
        }

        free_mem(args);
        free(input);
    }

    return 0;
}

