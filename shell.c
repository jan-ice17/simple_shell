#include "shell.h"

/**
 * main - Entry Point
 * 
 * @argc: Number of command-line arguments.
 * @argv: Array of strings containing command-line arguments.
 * 
 * Return - Exit status.
 */
int main(int argc, char **argv) {
    while (1) {
        char *cmd;
        char **args;

        display_prompt(); 
        cmd = read_command(); 
        args = split_string(cmd);
        _execute(args[0], args, argv[0]); 

        if (argc)
        {}
        
        free(args);
        free(cmd);
    }

    return (0);
}