#include "shell.h"

/**
 * get_help - function that retrieves help messages according builtin
 * @datash: data structure (args and input)
 * Return: Return 0
*/
int get_help(data_shell *datash)
{

	if (datash->args[1] == 0)
		help_builtins();
	else if (_strcmp(datash->args[1], "setenv") == 0)
		setenv_help();
	else if (_strcmp(datash->args[1], "env") == 0)
		env_help();
	else if (_strcmp(datash->args[1], "unsetenv") == 0)
		unsetenv_help();
	else if (_strcmp(datash->args[1], "help") == 0)
		help_info();
	else if (_strcmp(datash->args[1], "exit") == 0)
		exit_help();
	else if (_strcmp(datash->args[1], "cd") == 0)
		cd_help();
	else if (_strcmp(datash->args[1], "alias") == 0)
		alias_help();
	else
		write(STDERR_FILENO, datash->args[0],
		      _strlen(datash->args[0]));

	datash->status = 0;
	return (1);
}
