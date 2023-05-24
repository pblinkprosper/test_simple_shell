#include "shell.h"

/**
 * _getenv - this function gets the environment
 * @name: the name of the path
 *
 * Return: the pointer the path variable
 */
char *_getenv(char *name)
{
	char **ptr;
	size_t len;

	len = _strlen(name);
	for (ptr = environ; *ptr != NULL; ptr++)
	{
		if (_strncmp(*ptr, name, len) == 0 && (*ptr)[len] == '=')
			return (*ptr + len + 1);
	}
	return (NULL);
}

/**
 * handle_path - this function gets the path for the command
 * @cmd: the command to search its path
 *
 * Return: the pointer to the path
 */
char *handle_path(char *cmd)
{
	char *direc;
	char *path = _getenv("PATH");
	char *pathway = malloc(_strlen(path) + _strlen(cmd) + 2);

	if (!pathway)
		return (NULL);
	 direc = strtok(path, ":");
	while (direc)
	{
		_strcpy(pathway, direc);
		_strcat(pathway, "/");
		_strcat(pathway, cmd);
		if (access(pathway, F_OK) == 0)
			return (pathway);
		direc = strtok(NULL, ":");
	}
	free(pathway);
	return (NULL);
}

/**
 * exec_cmd - this function executes a command fed to it
 * @args: these are the arguments or commands
 * @arty: this is the argument type
 *
 * Return: this function returns nothing
 */
void exec_cmd(char **args, int arty)
{
	if (arty == EXTR_CMD)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
}
