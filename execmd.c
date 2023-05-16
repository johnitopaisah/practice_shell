#include "main.h"

/**
 * execmd - Function that handles the execution of commands
 * @argv: The array of string of the command
 * Return: Nothing.
 */
void execmd(char **argv)
{
	char *command = NULL, *actual_command = NULL;
	pid_t child_proc;
	int status;

	if (argv)
	{
		/* get the command */
		command = argv[0];

		/**
		 * generating the path to this command before
		 * passing it to the execve function
		 */
		actual_command = get_location(command);

		/* creating a child process to handle the execution of command separately */
		child_proc = fork();
		if (child_proc == -1)
		{
			free(argv);
			exit(EXIT_FAILURE);
		}
		if (child_proc == 0)
		{
			/* execute the command with execve */
			if (execve(actual_command, argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
			wait(&status);
	}
}
