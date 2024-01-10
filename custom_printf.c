#include "simple_shell.h"
#include <unistd.h>

/**
 * JanTee_printf - prints to stdout
 * @c: takes in characters
 * print_f - A custom printfhat writes text to STDOUT_FILENO.
 *
 * return: write statement
 */
int JanTee_printf(char c)
{
	return (write(1, &c, 1));
}
