#include "main.h"

/**
 * handle_exit - function that handles the 'exit' built-in command
 *
 * Return: Nothing
 */
void handle_exit(void)
{
	/* send a SIGTERM to the current processs */
	exit(0);
}
