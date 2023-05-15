#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int _putchar(char c);
void start_prompt(void);
char *line_command(void);
char **tok_parsing(char *lineptr, char *lineptr_copy);
void execmd(char **argv);
void free_mem(char **argv, char *lineptr, char *lineptr_copy);
char *copy_func(char *lineptr);


#endif /* MAIN_H */
