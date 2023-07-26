#include "shell.h"

/**
 * get_error - calls the error according the builtin, syntax or permission
 * @datash: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int get_error(data_shell *datash, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = env_error(datash);
		break;
	case 126:
		error = path_error(datash);
		break;
	case 127:
		error = error_msg(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			error = exit_sherr(datash);
		else if (_strcmp("cd", datash->args[0]) == 0)
			error = get_cderr(datash);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	datash->status = eval;
	return (eval);
}
