#include "shell.h"

/**
 * _env - this function prints the environment
 * @name: the name of the path
 *
 * Return: an integer
 */
int _env(char **name)
{
	int e = 0;
	int len = 0;
	char *dup = malloc(8192);

	while (name[e] != NULL)
	{
		len = _strlen(name[e]);
		dup = _strdup(name[e]);

		write(STDOUT_FILENO, dup, len + 1);
		write(1, "\n", 1);
		free(dup);
		e++;
	}
	return (1);
}

/**
 * _getenv - this function gets the environment
 * @env: the name of the environment
 * @str: the string containing the command
 *
 * Return: the pointer the path variable
 */
char *_getenv(char **env, char *str)
{
	char *ptr = NULL, *temp = malloc(sizeof(char *) * BUFFER);
	char *path = malloc(sizeof(char *) * BUFFER);
	int len = 0, m = 0, n = 0;
	int i = 0;

	while (*env)
	{
		path = _strdup(env[i]);
		ptr = strtok(path, "=");
		if (ptr != NULL && (_strcmp(ptr, str)) == 0)
		{
			path = _strdup(env[i]);
			while (ptr[++m])
				;
			n = m + 1;
			len = _strlen(path) - n;
			i = 0;
			while (i < len)
			{
				temp[i] = path[n];
				i++;
				n++;
			}
			free(path);
			return (temp);
		}
		free(path);
		i++;
	}
	free(temp);
	free(path);
	return (NULL);
}

/**
 * handle_path - this function gets the path for the command
 * @args: the command to search its path
 * @env: the environment variable
 *
 * Return: an integer
 */
int handle_path(char **args, char **env)
{
	pid_t pid, cpid;
	char *delim = "/";
	char *temp = NULL;
	int i = 0, j = 0;

	temp = _strdup(args[0]);
	if ((access(args[0], R_OK | X_OK)) == 0)
	{	pid = fork();
		if (pid == 0)
		{
			i = execve(args[0], args, env);
			if (i == -1)
			{
				perror("hsh");
			}
			exit(EXIT_SUCCESS);
		} else if (pid < 0)
			perror("hsh");
		else
			do {
				cpid = waitpid(pid, &i, WUNTRACED);
				if (cpid == -1)
					perror("hsh");
			} while (!WIFSIGNALED(i) && !WIFEXITED(i));
		free(temp);
		return (1);
	}	else if (temp != NULL)
	{
		for (j = 0; temp[j] != '\0'; j++)
		{
			if (temp[j] == delim[0])
			{
				errno = ENOENT;
				perror("hsh"), free(temp);
				return (1);
			}
		}
	}
	free(temp);
	return (0);
}

/**
 * get_f - this function selects the function used to execute a command
 * @cmd: this is the command
 * @env: this gets the environment
 *
 * Return: integer
 */
int get_f(char **cmd, char **env)
{
	int g = 0;
	char *builtin[6] = {"exit", "cd", "env", "unsetenv", "setenv", NULL};

	if (cmd[0] == NULL)
		return (1);
	while (builtin[g] != NULL)
	{
		if (_strcmp(builtin[g], cmd[0]) == 0)
			break;
		g++;
	}
	switch (g)
	{
	case 0:
		if (cmd[1] == NULL)
			exit_sh(cmd);
		else
			exit_message(cmd);
		break;
	case 1:
		_cd(cmd);
		break;
	case 2:
		_env(env);
		break;
	case 3:
		unset_env(env, cmd);
		break;
	case 4:
		set_env(env, cmd);
		break;
	default:
		return (exec_cmd(cmd, env));
	}
	return (g);
}
