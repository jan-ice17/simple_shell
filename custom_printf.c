#include "simple_shell.h"
#include <unistd.h>

/**
 * JanTee_printf - prints to stdout
 * @string: takes in characters
 *
 * return: write statement
 */
int JanTee_printf(const char *string)
{
	if (string == NULL)
	{
		return (-1);
	}
	size_t len = strlen(string);
	return (write(1, &string, len));
}
