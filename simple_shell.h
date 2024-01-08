#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/*All Protyotypes are included in this file*/


/*prototype for the display prompt*/
void prompt_text(void);

/*prototype for my custom printf function*/
void jan_printf(const char *text);

/*Prototype to execute all commands*/
void exec_a_command(char *user_cmd);

/*Prototype to read user input*/
char *read_user_input(void);




#endif /*SIMPLE_SHELL_H*/
