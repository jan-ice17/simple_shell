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


#define BUFFER_SIZE 1024

size_t _strspn(const char *str, const char *accept);
size_t _strcspn(const char *str, const char *reject);
size_t _strlen(const char *str);
ssize_t _getline(char **lineptr, size_t *n, int fd);
char *_strtok(char *str, const char *delim);
char *_strchr(const char *s, char c);
char *read_command();
char **split_string(char *command);
void _printf(const char *str);
void display_prompt();
void *_realloc(void *ptr, size_t size);
void _execute(const char *file_path, char **const args, const char *program_name);


typedef struct header {
    struct header *next;
    size_t size;
    bool is_free;
} header_t;

#endif /*SHELL_H*/