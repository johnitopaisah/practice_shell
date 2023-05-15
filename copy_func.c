#include "main.h"

/**
 * copy_func - this function will copy the content
 * @lineptr: the pointer to copy from
 *
 * Return: Return pointer to the copied content
 */
char *copy_func(char *lineptr)
{
	char *lineptr_copy;

	/* allocate enough memory for the lineptr_copy */
	lineptr_copy = malloc(sizeof(char *) * strlen(lineptr) + 1);
	if (lineptr_copy == NULL)
	{
		perror("tsh: memory allocation error");
		exit(0);
	}
	/* copy the content of lineptr to lineptr_copy */
	strcpy(lineptr_copy, lineptr);

	return (lineptr_copy);
}
