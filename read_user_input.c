#include "simple_shell.h"

/**
 * *read_user_input - Reads user input from stdin.
 * read
 *
 * Return: A pointer to the user input string.
 */
char **read_input(void)
{
	char *user_input = NULL;
	size_t buf_size = 0;
	ssize_t get_line;

	get_line = getline(&user_input, &buf_size, stdin);
	if (get_line == -1)
	{
		perror(":( ERROR");
		exit(EXIT_FAILURE);
	}
	tokenized_input = tokenize_input(user_input);
	free(user_input);

	return (tokenized_input);
}
