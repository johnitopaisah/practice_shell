#include "main.h"

/**
 * tok_parsing - function for tokenization and parsing.
 * @lineptr: comman gotten from the stdin
 * @lineptr_copy: a copy of lineptr
 *
 * Return: returns the array of string of the command
 */

char **tok_parsing(char *lineptr, char *lineptr_copy)
{
	char *token;
	const char *delim = " \n";
	char **argv;
	int num_tokens = 0, i;

	token = strtok(lineptr, delim);
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	/* allocating space to hold the array of strings */
	argv = malloc(sizeof(char *) * num_tokens + 1);
	if (argv == NULL)
	{
		perror("tsh: memory allocation error");
		exit(0);
	}
	/* store each token in the argv array */
	token = strtok(lineptr_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token) + 1);
		if (argv[i] == NULL)
		{
			perror("tsh: memory allocation error");
			exit(0);
		}
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	return (argv);
}
