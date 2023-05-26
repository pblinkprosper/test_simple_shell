#include "shell.h"

/**
 * check_cmd - this function checks the command entered
 * @args: the string
 * @env: the environment
 * @nstr: the new string
 * @path: the path where the command exists
 * @npath: the new path created
 *
 * Return: an integer
 */
int check_cmd(char **args, char **env, char *nstr, char *path, char *npath)
{
	if ((handle_path(args, env)) == 1)
		return (1);
	if (nstr == NULL || path == NULL || npath == NULL)
		exit_sh(NULL);
	return (0);
}

/**
 * parse_cmd - this function checks the command to determine its type
 * @cmd: the command to be checked
 *
 * Return: returns and integer
 */
char **parse_cmd(char *cmd)
{
	int buff = BUFFER;
	int i = 0;
	char **tokens = NULL;
	char *input = NULL;

	tokens = malloc(sizeof(char *) * buff);
	if (!tokens)
	{
		perror("hsh");
		exit(EXIT_FAILURE);
	}
	input = strtok(cmd, DELIM);

	while (input != NULL)
	{
		tokens[i] = input;
		input = strtok(NULL, DELIM);
		i++;
	}
	if (i >= buff)
	{
		buff += BUFFER;
		tokens = _realloc(tokens, BUFFER, buff * sizeof(char *));

		if (!tokens)
		{
			{
				perror("hsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		input = strtok(NULL, DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * exit_sh - this function exits the shell
 * @arg: the command fed to the shell
 *
 * Return: nothing
 */
void exit_sh(char **arg)
{
	free(*arg);
	free(arg);
	exit(EXIT_SUCCESS);
}
