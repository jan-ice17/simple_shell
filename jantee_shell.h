#ifndef JANTEE_SHELL_H
#define JANTEE_SHELL_H
#define MAX_ARGS 64
#define BUFSIZE 1024


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>


char *jan_read_input(void);
void jan_display_prompt(void);
void jan_exec_command(char **args);
void free_mem(char **args);
char **parse_input(char *input);
extern char *progr_name;

#endif /* JANTEE_SHELL_H */
