#include "shell.h"

/**
 * main - this function creates a user defined shell environment
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char *cmd_arg = NULL, *prompt = "$ ";
	char **argv = NULL, **token = NULL;
	size_t n = 0;
	int argc = 0, i;

	while (1)
	{
		write(STDOUT_FILENO, prompt, 2);
		if (getline(&cmd_arg, &n, stdin) == -1)
		{
			free(cmd_arg);
			exit(0);
		}
		newline_handle(cmd_arg);
		argv = make_token(cmd_arg, ";");

		for (i = 0; argv[i]; i++)
		{
			token = make_token(argv[i], " ");
			if (token[0] == NULL)
			{
				free(token);
				break;
			}
			argc = parse_cmd(token[0]);
			init_shell(token, argc);
			free(token);
		}
		free(argv);
	}
	free(cmd_arg);
	return (0);
}
