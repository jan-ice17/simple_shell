#include "simple_shell.h"

/**
 * jan_printf - A custom printfhat writes text to STDOUT_FILENO.
 *
 * Return: NUll
 */
void jan_printf(const char *text)
{
    write(STDOUT_FILENO, text, strlen(text));
}

