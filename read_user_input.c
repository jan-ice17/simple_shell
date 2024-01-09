#include "simple_shell.h"

/**
 * read_input - Reads user input from stdin.
 *
 * Return: A pointer to the user input string.
 */
char *read_input(void)
{
	char *user_input = NULL;
	size_t buff_size = 0;
	ssize_t read_usr_input;

	read_usr_input = getline(&user_input, &buff_size, stdin)
	if (read_usr_input == -1)
	{
		perror(":( ERROR");
		exit(EXIT_FAILURE);
	}
	return (user_input);
}

