#include "main.h"

ssize_t cust_getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[1024];
	static int position = 0;
	static int bytes_read = 0;
	ssize_t line_length = 0, i;
	char *line = NULL;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	while (1)
	{
		/* check if buffer needs to be refilled */
		if (position >= bytes_read)
		{
			bytes_read = fread(buffer, 1, sizeof(buffer), stream);
			if (bytes_read <= 0)
				/* end of file or error */
				return (-1);
			position = 0;
		}
		/* check for newline character in buffer */
		while (position < bytes_read)
		{
			if (buffer[position] == '\n')
			{
				/* allocate memory for the line */
				line = realloc(line, line_length + 1);
				if (line == NULL)
					return (-1);
				/* copy the line from buffer to allocated memory */
				for (i = 0; i < line_length; i++)
					line[i] = buffer[i];
				line[line_length] = '\0';
				/* update lineptr and n */
				*lineptr = line;
				*n = line_length;
				/* move buffer position to next character */
				position++;
	
				return (line_length);
			}
			/* move buffer posion and increase line length */
			position++;
			line_length++;
		}
	}
}
