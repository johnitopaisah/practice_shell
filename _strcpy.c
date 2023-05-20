#include "main.h"

/**
 * _strcpy - function that copies the string pointed
 * @dest: pointer to the destination
 * @src: pointer to the source
 *
 * Return: characters
 */
char *_strcpy(char *dest, char *src)
{
	char *start_pt = dest;

	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (start_pt);
}
