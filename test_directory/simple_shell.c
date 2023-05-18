#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	char *cmd_arg = NULL, *prompt = "my@simpleshell> ";
	char *cmd_argcpy = NULL;
	char *token = NULL;
	char *delimiter = " \n";
	size_t n = 0;
	char **argv = NULL;
	int argc = 0, i = 0, read_arg;

	read_arg = write(STDOUT_FILENO, prompt, 16);
	if (getline(&cmd_arg, &n, stdin) == -1)
		return (-1);
	cmd_argcpy = strdup(cmd_arg);

	token = strtok(cmd_arg, delimiter);
	
	while (token)
	{
		token = strtok(NULL, delimiter);
		argc++;
	}

	printf("%d\n", argc);
	
	argv = malloc(sizeof(char *) * argc);

	token = strtok(cmd_argcpy, delimiter);
	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, delimiter);
		i++;
	}
	argv[i] = NULL;

	i = 0;
	while (argv[i])
		printf("%s\n", argv[i++]);

	free(cmd_arg);
	free(cmd_argcpy);
	free(argv);
	return (0);
}
