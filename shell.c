#include "simple_shell.h"

/**
 * main - Shell program that runs shell commands.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *user_cmd;

	while (1)
	{
		void display_prompt(void)(); /* Display the Shell prompt */
		user_cmd = read_user_input(); /* Read Input from User */

		if (!user_cmd)
		{
			break; /* Break the loop on EOF (Ctrl+D) */
		}

		exec_a_command(user_cmd); /* Execute the user's command */
		free(user_cmd);
	}

	JanTee_printf("\n"); /*A command line always ends with a new line.*/
	return (0);
}
