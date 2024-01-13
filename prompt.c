#include "jantee_shell.h"

/**
 * jan_display_prompt - Display the shell prompt
 *
 * Description: Displays the prompt "JANTEE/$ ".
 *
 * Return: void
 */
void jan_display_prompt(void)
{
	write(STDOUT_FILENO, "JANTEE/$ ", 9);
}

/**
 * jan_read_input - Read input from the user
 *
 * Description: Reads input from the user using getline.
 *
 * Return: A pointer to the input string, or NULL on failure.
 */
char *jan_read_input(void)
{
	char *input = NULL;
	ssize_t read_bytes;
	size_t len = 0;

	jan_display_prompt();
	read_bytes = getline(&input, &len, stdin);

	if (read_bytes == -1)
	{
		if (feof(stdin))
		{
			free(input);
			return (NULL);
		}
		else
		{
			perror(progr_name);
			exit(EXIT_FAILURE);
		}
	}

	if (input[read_bytes - 1] == '\n')
	{
		input[read_bytes - 1] = '\0';
	}

	return (input);
}
