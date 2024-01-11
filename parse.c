#include "jantee_shell.h"

/**
 * parse_input - Tokenizes the input string into an array of arguments.
 * @input: The input string to be parsed.
 *
 * Return: An array of pointers to the parsed arguments.
 */
char **parse_input(char *input)
{
	char *token;
	int i;
	char **args = malloc(MAX_ARGS * sizeof(char *));

	if (args == NULL)
	{
		perror(progr_name);
		exit(EXIT_FAILURE);
	}

	token = strtok(input, " ");
	i = 0;

	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i++] = strdup(token);
		if (args[i - 1] == NULL)
		{
			perror(progr_name);
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, " ");
	}

	args[i] = NULL;
	return (args);
}
