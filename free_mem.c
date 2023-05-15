#include "main.h"

void free_mem(char **argv, char *lineptr, char *lineptr_copy)
{
	int i;

	for (i = 0; argv[i]; i++)
	{
		free(argv[i]);
	}
	free(argv);
	free(lineptr_copy);
	free(lineptr);
}
