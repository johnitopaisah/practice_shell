#include "main.h"
/**
 * main- The entry point
 * Return: Always 0.
 */
int main(void)
{
	char **argv;
	char *lineptr, *lineptr_copy;

	/* Creating an infinite loop for the shell's prompt */
	while (1 == 1)
	{
		start_prompt();

		lineptr = line_command();
		lineptr_copy = copy_func(lineptr);

		argv = tok_parsing(lineptr, lineptr_copy);

		execmd(argv);

		free_mem(argv, lineptr, lineptr_copy);
	}

	return (0);
}
