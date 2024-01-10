#include "simple_shell.h"
#include <unistd.h>

/**
 * JanTee_printf - prints to stdout
 * @c: takes in characters
 *
 * return: write statement
 */
int JanTee_printf(char c)
{
	return (write(1, &c, 1));
}
