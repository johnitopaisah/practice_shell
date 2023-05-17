#include "main.h"

/**
 * handle_exit - function that handles the 'exit' built-in command
 * @argv: the command to compare with 'exit'
 *
 * Return: Nothing
 */
void handle_exit(char **argv)
{
	int check;

	check = strcmp(argv[0], "exit");
	if (check == 0)
	{
		perror("Exiting shell....\n");
		exit(EXIT_FAILURE);
	}
}
