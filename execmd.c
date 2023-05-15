#include "main.h"

/**
 * execmd - Function that handles the execution of commands
 * @argv: The array of string of the command
 * Return: Nothing.
 */
void execmd(char **argv)
{
	char *command = NULL;

	if (argv)
	{
		/* get the command */
		command = argv[0];

		/* execute the command with execve */
		if (execve(command, argv, NULL) == -1)
		{
			perror("Error:");
		};
	}
}
