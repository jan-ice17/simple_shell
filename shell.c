#include "simple_shell.h"

/**
 * main - Shell program that runs shell commands.
 *
 * Return: Always 0.
 */
int main(void)
{
	char **command_args;

	while (1)
	{
		void display_prompt(void)(); /* Display the Shell prompt */
		command_args = read_input(); /* Read Input from User */

		if (!command_args)
		{
			break; /* Break the loop on EOF (Ctrl+D) */
		}

		execute_cmd(command_args); /* Execute the user's command */
		free(command_args);
	}
	JanTee_printf("\n"); /*A command line always ends with a new line.*/
	return (0);
}
