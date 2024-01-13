#include "shell.h"

/**
 * _printf - Custom format function
 * @str: String to be printed
 */
void _printf(const char *str) {
    if (str != NULL) {
        int len = _strlen(str);
        write(STDOUT_FILENO, str, len);
    }
}

