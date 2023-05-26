#include "shell.h"

/**
 * env_var - this function sets the environment variable
 * @env: the environment vairable
 * @arg: arguments to the environment vairable
 *
 * Return: an integer
 */
int env_var(char **env, char *arg)
{
	char *token = NULL;
	char *path = malloc(sizeof(char) * BUFFER);
	int a = 0;

	while (*env)
	{
		path = _strdup(env[a]);
		token = strtok(path, "=");

		if (token != NULL && (_strcmp(token, arg)) == 0)
		{
			free(path);
			return (a);
		}
		free(path);
		a++;
	}
	return (0);
}

/**
 * unset_env - this function unsets the environment
 * @env: the environment vairable
 * @arg: arguments to the environment vairable
 *
 * Return: an integer
 */
int unset_env(char **env, char **arg)
{
	int y = 0;

	if (arg == NULL || arg[1] == NULL || arg[1][0] == '\0')
	{
		errno = EINVAL;
		perror("hsh");
		return (1);
	}
	y = env_var(env, arg[1]);
	while (env[y] != NULL)
	{
		env[y] = env[y + 1];
		y++;
	}
	return (1);
}

/**
 * set_env - this function sets the environment
 * @env: the environment vairable
 * @arg: arguments to the environment vairable
 *
 * Return: an integer
 */
int set_env(char **env, char **arg)
{
	int f = 0, g = 0, h = 0;
	char *temp = NULL, *temp2 = NULL;

	printf("%s\n", arg[1]);
	printf("%s\n", env[0]);

	f = env_var(env, arg[1]);
	printf("%s\n", env[f]);
	if (f != 0 && arg[3] != 0)
	{
		h = _strlen(env[f]);
		unset_env(env, arg);

		g = (_strlen(arg[1]) + _strlen(arg[2]) + 2);

		temp2 = malloc(BUFFER);
		temp = malloc(g);

		temp2 = _strcat(arg[1], "=");
		temp = _strcat(temp2, arg[2]);
		_realloc(env[f], h, _strlen(temp));
		env[f] = temp;
	}
	return (1);
}
