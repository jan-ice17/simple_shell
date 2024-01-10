#include "simple_shell.h"

/**
 * *read_user_input - Reads user input from stdin.
 * read_input - Reads user input from stdin.
>>>>>>> 706f1cd07f5a1b6026b223cc7a7a41e197ea01a0
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
		perror(":)");
		free (user_input);
		return (NULL);
	}
	return (user_input);
/**
	size_t buff_size = 0;
	ssize_t read_usr_input;

	char **tokenized_input;

	read_usr_input = getline(&user_input, &buff_size, stdin);
	if (read_usr_input == -1)
	{
		perror(":( ERROR");
		exit(EXIT_FAILURE);
	}

	tokenized_input = tokenize_input(user_input);

	free(user_input); /*Free user original output

	return (tokenized_input);*/
}
