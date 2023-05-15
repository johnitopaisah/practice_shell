#include "main.h"

/**
 * execmd - Function that handles the execution of commands
 * @argv: The array of string of the command
 * Return: Nothing.
 */
void execmd(char **argv)
{
	char *command = NULL, *actual_command = NULL;

	if (argv)
	{
		/* get the command */
		command = argv[0];

		/**
		 * generating the path to this command before
		 * passing it to the execve function
		 */
		actual_command = get_location(command);

		/* execute the command with execve */
		if (execve(actual_command, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
