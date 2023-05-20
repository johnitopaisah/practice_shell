#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


int _putchar(char c);
void start_prompt(void);
char *line_command(void);
char **tok_parsing(char *lineptr, char *lineptr_copy);
void execmd(char **argv);
void free_mem(char **argv, char *lineptr, char *lineptr_copy);
char *copy_func(char *lineptr);
char *get_location(char *command);
char *path_help(char *path, char *command);
void handle_exit(void);
void handle_env();
ssize_t cust_getline(char **lineptr, size_t *n, FILE *stream);


#endif /* MAIN_H */
