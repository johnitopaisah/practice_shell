#include "main.h"

/**
 * line_command - function that get command from the user
 *
 * Return: on success the function the command
 */
char *line_command(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	int i = 0;

	nchars_read = getline(&lineptr, &n, stdin);
	/* check if getline function failed or CTRL +D was entered */
	if (nchars_read == -1)
	{
		perror("Exiting...");
		exit(EXIT_FAILURE);
	}
	if (lineptr == NULL)
		return NULL;
	/* Handling EOF */
	while (lineptr[i])
	{
		if (lineptr[i] == '\n')
			lineptr[i] = '\0';
		i++;
	}

	return (lineptr);
}
