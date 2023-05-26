#include "shell.h"

/**
 * exit_message - this function prints a message on exit
 * @arg: the arguments fed to the function
 *
 * Return: an integer
 */
int exit_message(char **arg)
{
	int message;

	message = _quit_atoi(arg[1]);

	if (message == -1)
	{
		perror("hsh");
		return (0);
	}
	else
	{
		exit(message);
	}
}

/**
 * _cd - change directory
 * @arg: arguments to execute
 *
 * Return: an integer
 */
int _cd(char **arg)
{
	char *dir = NULL;
	char *home = NULL;

	home = _getenv(environ, "HOME");
	if (arg[1])
	{
		if (_strcmp(arg[1], "~"))
			dir = home;

		else if (_strcmp(arg[1], "-"))
			dir = _getenv(environ, "OLDPWD");
		else
			dir = arg[1];
	}
	else
		dir = home;

	if (dir == home)
		chdir(dir);
	else if (access(dir, F_OK | R_OK) == 0)
		chdir(dir);
	else
		perror("hsh");
	return (0);
}
