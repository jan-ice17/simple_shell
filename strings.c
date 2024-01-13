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
 * _strlen - Calculate length of string.
 * @s: The string to calculate the length of.
 *
 * Return: Length of the string, or 0 if s is NULL.
 */
size_t _strlen(const char *s) {
    size_t length = 0;
    if (s == NULL) {
        return 0;
    }

    while (*s++) {
        length++;
    }
    return length;
}