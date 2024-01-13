#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BUFFER_SIZE 1024  /*buff size*/


/*All Protyotypes are included in this file*/

/*prototype for the display prompt*/
void display_prompt(void);

/*prototype for my custom printf function*/
int JanTee_printf(const char *str);

/*Prototype to execute all commands*/
int execute_cmd(char *command_args[]);

/*Prototype to read user input*/
char **read_input(void);

/*Prototype for parsing user input into args*/
char **tokenize_input(char *input_line);

#endif /*SIMPLE_SHELL_H*/
