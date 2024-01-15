#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/wait.h>  
#include <ctype.h>


#define BUFFER_SIZE 1024

size_t _strspn(const char *str, const char *accept);
size_t _strcspn(const char *str, const char *reject);
size_t _strlen(const char *str);
int _atoi(const char *str); 
char *_strtok(char *str, const char *delim);
char *_strchr(const char *s, char c);
char *_strdup(const char *s);
void _strcat(char *dest, const char *src);
void _strcpy(char *dest, char *src);
void *_realloc(void *old_ptr, size_t new_size);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(const char *str1, const char *str2);
char *read_command();
char **split_string(char *command);
void _printf(const char *str);
void display_prompt();
void _execute(const char *file_path, char **const args, const char *program_name);
ssize_t _getline(char **lineptr, size_t *n, int fd);

#endif /*SHELL_H*/