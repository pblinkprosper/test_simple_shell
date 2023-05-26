#include "shell.h"

/**
 * read_line - Reads args with getline
 *
 * Return: void
 */

char *read_line(void)
{
	char *n = NULL;
	size_t buff = 0;
	int i = 0;

	i = getline(&n, &buff, stdin);

	if (i == EOF)
	{
		if ((isatty(STDIN_FILENO)) == 1)
			write(1, "\n", 1);
		exit(0);
	}
	return (n);
}
