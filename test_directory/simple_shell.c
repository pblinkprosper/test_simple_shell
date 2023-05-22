#include "shell.h"

int main(void)
{
	char *cmd_arg = NULL, *prompt = "my@simpleshell> ";
	char **argv = NULL, **token = NULL;
	size_t n = 0;
	int i, read_arg;

	read_arg = 0;
	while (1)
	{
		read_arg = write(STDOUT_FILENO, prompt, 16);
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
			free(token);
		}
		free(argv);
	}
	free(cmd_arg);
	return (0);
}
