#include "shell.h"

/**
 * main - this function creates a user defined shell environment
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char *buff = NULL;
	char **argv;
	int i = 1;
	int argc = 0;

	while (i)
	{
		signal(SIGINT, handle_ctrl_c);

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		buff = read_line();
		argv = parse_cmd(buff);
		i = get_f(argv, environ);
		free(argv);
		free(buff);
		argc++;
	}
	return (0);
}

/**
 * handle_ctrl_c - this handles pressing Ctrl + C
 * @sig: this is the signal number
 *
 * Return: returns void
 */
void handle_ctrl_c(int sig __attribute__((unused)))
{
	signal(SIGINT, handle_ctrl_c);
	write(STDOUT_FILENO, "\n$ ", 3);
}
