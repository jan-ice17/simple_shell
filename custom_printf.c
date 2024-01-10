#include "simple_shell.h"
#include <unistd.h>

/**
 * JanTee_printf - prints to stdout
 * @string: takes in characters
 *
 * Return: write statement
 */
int JanTee_printf(const char *string)
{
	size_t len;

	if (string == NULL)
	{
		return (-1);
	}
	len = strlen(string);

	return (write(1, string, len));
}
