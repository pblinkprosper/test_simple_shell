#include "shell.h"

/**
 * make_token - makes strings received from stdin into tokens
 * @str_in: the input string
 * @delim: the delimiter to use in separating the strings
 *
 * Return: the argument vector
 */
char **make_token(char *str_in, char *delim)
{
	char *token = NULL, *ptr = NULL;
	char **argv = NULL;
	int n = 0;

	token = _strtok_r(str_in, delim, &ptr);

	while (token)
	{
		argv = _realloc(argv, sizeof(*argv) * n, sizeof(*argv) * (n + 1));
		argv[n] = token;
		token = _strtok_r(NULL, delim, &ptr);
		n++;
	}
	argv = _realloc(argv, sizeof(*argv) * n, sizeof(*argv) * (n + 1));
	argv[n] = NULL;

	return (argv);
}

/**
 * newline_handle - this function removes the newline appended by the string
 * @str: the string
 *
 * Return: void (nothing)
 */
void newline_handle(char *str)
{
	int count = 0;

	while (str[count] != '\0')
	{
		if (str[count] == '\n')
			break;
		count++;
	}
	str[count] = '\0';
}

/**
 * _strtok_r - this function tokenises a string
 * @str: string to be tokenised
 * @delim: the separator for the strings
 * @ptr: the pointer to save the string
 *
 * Return: returns pointer to the next token
 */
char *_strtok_r(char *str, char *delim, char **ptr)
{
	char *token;

	if (!str)
		str = *ptr;
	if (*str == '\0')
	{
		*ptr = str;
		return (NULL);
	}

	str += _strspn(str, delim);
	if (*str == '\0')
	{
		*ptr = str;
		return (NULL);
	}
	token = str + _strcspn(str, delim);
	if (*token == '\0')
	{
		*ptr = token;
		return (str);
	}
	*token = '\0';
	*ptr = token + 1;
	return (str);
}

/**
 * _realloc - this function reallocates a memory block using malloc
 * @ptr: this is the pointer to a memory block previously allocated with malloc
 * @old_size: this is the size in bytes of the allocated space for ptr
 * @new_size: this is the new size of the new memory block
 *
 * Return: returns nothing
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		ptr = malloc(new_size);
	if (new_size == old_size)
		return (ptr);

	free(ptr);
	ptr = malloc(new_size);

	return (ptr);
}

/**
 * parse_cmd - this function checks the command to determine its type
 * @cmd: the command to be checked
 *
 * Return: returns and integer
 *
int parse_cmd(char *cmd)
{
	char *path = NULL;
	char *intr_cmd[] = {"env", "exit", NULL};
	int n;

	for (n = 0; cmd[n]; n++)
	{
		if (cmd[n] == '/')
			return (EXTR_CMD);
	}
	for (n = 0; intr_cmd[n]; n++)
	{
		if (_strcmp(cmd, intr_cmd[n]) == 0)
			return (INTR_CMD);
	}
	path = path_handle(cmd);
	if (path)
	{
		free(path);
		return (PATH_CMD);
	}
	return (INVL_CMD);
}
*/
