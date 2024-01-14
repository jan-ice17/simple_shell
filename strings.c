#include "shell.h"

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


/**
 * _strdup - Duplicates a string.
 * @s: The string to be duplicated.
 *
 * Return: Pointer to the duplicated string, or NULL if insufficient memory
 *         was available.
 */
char *_strdup(const char *s) {
    char *dup;
    size_t len, i;

    if (s == NULL) {
        return NULL;
    }

    len = _strlen(s);

    dup = malloc(sizeof(char) * (len + 1));

    if (dup == NULL) {
        return NULL;
    }

    for (i = 0; i < len; i++) {
        dup[i] = s[i];
    }

    dup[i] = '\0';

    return dup;
}


/**
 * _strcat - Concatenates two strings.
 * @dest: The string to be appended to.
 * @src: The string to append.
 * 
 */
void _strcat(char *dest, const char *src) {
    int i, j;
    for (i = 0; dest[i] != '\0'; i++);
    for (j = 0; src[j] != '\0'; j++) {
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
}


/**
 * _strcpy - Copies a string.
 * @dest: The destination string.
 * @src: The source string.
 * 
 */
void _strcpy(char *dest, char *src) {
    int i;
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}