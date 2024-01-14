#include "shell.h"

/**
 * _strchr - Locates a character in a string.
 * @s: The string to search.
 * @c: The character to locate.
 *
 * Return: Pointer to first occurrence of character c in the string s
 */
char *_strchr(const char *s, char c) {
    if (s == NULL) {
        return NULL;
    }

    while (*s) {
        if (*s == c)
            return (char *)s;
        s++;
    }
    return NULL;
}

/**
 * _strspn - Gets length of a prefix substring.
 * @s: The string to be searched.
 * @accept: The string containing the characters to match.
 *
 * Return: No. of bytes in initial segment of s.
 */
size_t _strspn(const char *s, const char *accept) {
    size_t count = 0;
    if (s == NULL || accept == NULL) {
        return 0;
    }

    while (*s && _strchr(accept, *s++))
        count++;

    return count;
}

/**
 * _strcspn - Gets length of a prefix substring.
 * @s: The string to be searched.
 * @reject: The string containing the characters to avoid.
 *
 * Return: Num. of bytes in initial segment of s which consist only
 *         of bytes NOT in reject, or 0 if s or reject is NULL.
 */
size_t _strcspn(const char *s, const char *reject) {
    size_t c = 0;
    if (s == NULL || reject == NULL) {
        return 0;
    }

    while (*s && !_strchr(reject, *s++))
        c++;

    return c;
}


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