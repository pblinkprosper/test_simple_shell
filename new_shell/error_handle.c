#include "shell.h"
/**
 * concat_cderr - this function concatenates the message for cd error
 *
 * @datash: data relevant (directory)
 * @msg: message to print
 * @error: output message
 * @ver_str: counter lines
 * Return: error message
 */
char *concat_cderr(data_shell *datash, char *msg, char *error, char *ver_str)
{
	char *bad_flag;

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	if (datash->args[1][0] == '-')
	{
		bad_flag = malloc(3);
		bad_flag[0] = '-';
		bad_flag[1] = datash->args[1][1];
		bad_flag[2] = '\0';
		_strcat(error, bad_flag);
		free(bad_flag);
	}
	else
	{
		_strcat(error, datash->args[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * get_cderr - finds error message for cd command in get_cd
 * @datash: data relevant (directory)
 * Return: Error message
 */
char *get_cderr(data_shell *datash)
{
	int len, len_id;
	char *err, *ver_str, *msg;

	ver_str = int_2str(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(datash->args[1]);
	}

	len = _strlen(datash->av[0]) + _strlen(datash->args[0]);
	len += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	err = malloc(sizeof(char) * (len + 1));

	if (err == 0)
	{
		free(ver_str);
		return (NULL);
	}

	err = concat_cderr(datash, msg, err, ver_str);

	free(ver_str);

	return (err);
}

/**
 * error_msg - a generic error message for "command not found"
 * @datash: data relevant (counter, arguments)
 * Return: Error message
 */
char *error_msg(data_shell *datash)
{
	int len;
	char *err;
	char *ver_str;

	ver_str = int_2str(datash->counter);
	len = _strlen(datash->av[0]) + _strlen(ver_str);
	len += _strlen(datash->args[0]) + 16;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err);
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, ": not found\n");
	_strcat(err, "\0");
	free(ver_str);
	return (err);
}

/**
 * exit_sherr - a generic error message for exit in get_exit
 * @datash: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *exit_sherr(data_shell *datash)
{
	int len;
	char *err;
	char *ver_str;

	ver_str = int_2str(datash->counter);
	len = _strlen(datash->av[0]) + _strlen(ver_str);
	len += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, ": Illegal number: ");
	_strcat(err, datash->args[1]);
	_strcat(err, "\n\0");
	free(ver_str);

	return (err);
}
