#include "simple_shell.h"

/**
 * print_f - A custom printfhat writes text to STDOUT_FILENO.
 *
 * Return: NUll
 */
void print_f(const char *text)
{
    write(STDOUT_FILENO, text, strlen(text));
}

