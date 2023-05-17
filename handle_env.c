#include "main.h"

/**
 * handle_env - Implement the env built-in, that
 * prints the current environment
 *
 * Return: Nothing
 */
void handle_env(void)
{
	extern char **_environ;
	char **_envp = _environ;

	while (*_envp)
	{
		printf("%s\n", *_envp);
		_envp++;
	}
}
