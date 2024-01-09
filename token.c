#include "simple_shell.h"

/**
 * tokenize_input - Tokenizes a given input line into an array of strings.
 * @input_line: The input line to tokenize.
 *
 * Return: An array of strings (tokens).
 */
char **tokenize_input(char *input_line)
{
	const char delimiters[] = " \t\n";
	char *token;
	char **tokens = malloc(BUFFER_SIZE * sizeof(char *));
	int token_index = 0;

	if (!tokens)
	{
		perror(":( Allocation error");
		exit(EXIT_FAILURE);
	}

	/* Tokenize an input line */
	token = strtok(input_line, delimiters);
	while (token != NULL)
	{
		tokens[token_index++] = strdup(token);
		if (!tokens[token_index - 1])
		{
			perror(":( Allocation error");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delimiters);
	}

	tokens[token_index] = NULL; /* Set the last element to NULL */
	return (tokens);
}

