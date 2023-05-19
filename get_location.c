#include "main.h"

/**
 * get_location - function that gets the path of the command typed.
 * @command: the command to get its path
 *
 * Return: Return the path if exit or NULL upon failure
 */
char *get_location(char *command)
{
	char *path;
	struct stat buff;
	char *location;

	path = getenv("PATH");

	if (path)
	{
		location = path_help(path, command);

		/* testing to know if the command itself is a path */
		if (stat(command, &buff) == 0)
		{
			return (command);
		}
		/* check if the command is not a valid command */
		if (location != NULL && strcmp(command, location) != 0)
		{
			return (location);
		}
	}

	return (NULL);

