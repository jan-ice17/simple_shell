#include "shell.h"

/**
 * _strtok - Breaks string into sequence of 0+ tokens.
 * @str: The string to tokenize.
 * @delim: The delimiter characters.
 *
 * Return: Pointer to next token, or NULL if there are no more tokens or if str or delim is NULL.
 */
char* _strtok(char* str, const char* delim) {
    /* Static pointer used to track the original string */
    static char* p = 0;

    /* If str is not null, set p to str */
    if(str) p = str;
    /* If str is null and p is also null, return null */
    else if(!p) return 0;

    /* Move str pointer to the first character not in delim */
    str = p + strspn(p, delim);

    /* Move p pointer to the next delimiter in str */
    p = str + strcspn(str, delim);

    /* If p and str point to the same location, set p to null and return null */
    if(p == str) return p = 0;

    /* If the character at p is not null, set it to null and move p to the next character */
    /* If the character at p is null, set p to null */
    p = *p ? *p = 0, p + 1 : 0;

    /* Return the original or modified str */
    return str;
}