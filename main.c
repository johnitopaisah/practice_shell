#include "main.h"
/**
 * main- The entry point
 * Return: Always 0.
 */
int main(void)
{
	char **argv;
	char *lineptr, *lineptr_copy;
	int is_input_tty = isatty(STDIN_FILENO);

	/* Creating an infinite loop for the shell's prompt */
	while (1 == 1)
	{
		if (is_input_tty)
		{
			start_prompt();
			fflush(stdout);
		}

		lineptr = line_command();
		if (lineptr == NULL)
			break;

		if (strcmp(lineptr, "Enter") == 0)
			continue;

		lineptr_copy = copy_func(lineptr);

		argv = tok_parsing(lineptr, lineptr_copy);

		if (strcmp(argv[0], "exit") == 0)
			handle_exit();
		else if (strcmp(argv[0], "env") == 0)
			handle_env();
		else
			execmd(argv);
		free_mem(argv, lineptr, lineptr_copy);
	}
	return (0);
}
