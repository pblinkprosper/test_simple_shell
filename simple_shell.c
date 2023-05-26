#include "shell.h"

/**
 * main - this function creates a user defined shell environment
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char *prompt = "$ ", *buff = NULL;
	char **argv;
	int argc = 0, i = 1;

	while (i)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, 2);
		buff = read_line();
		argv = parse_cmd(buff);
		i = get_f(argv, environ);
		free(argv);
		free(buff);
		argc++;
	}
	return (0);
}
