#include "shell.h"

/**
 * exec_cmd - this function executes a command fed to it
 * @args: these are the arguments or commands
 * @env: this is the environment
 *
 * Return: this function returns nothing
 */
int exec_cmd(char **args, char **env)
{
	pid_t pid, cpid;
	int i = 0;
	char *nstr = malloc(8 * BUFFER);
	char *path = malloc(8 * BUFFER);
	char *nstr2 = malloc(sizeof(char) * BUFFER), *npath = NULL;

	if (check_cmd(args, env, nstr, path, nstr2))
		return (1);
	nstr2 = _getenv(env, "PATH");
	npath = _strcat("/", args[0]);
	pid = fork();
	if (pid == 0)
	{	path = strtok(nstr2, ":");
		while (path)
		{
			nstr = _strcat(path, npath);
			if ((access(nstr, X_OK)) == 0)
			{
				free(npath);
				i = execve(nstr, args, env);
				if (i == -1)
					perror("hsh");
			}
			free(nstr);
			path = strtok(NULL, ":");
		}
		write(STDERR_FILENO, "hsh", _strlen("hsh") + 1);
		write(2, args[0], _strlen(args[0]));
		write(2, ": No such file or directory\n", 28);
		exit(EXIT_SUCCESS);
	} else if (pid < 0)
		perror("hsh");
	else
		do {
			cpid = waitpid(pid, &i, WUNTRACED);
			if (cpid == -1)
				perror("hsh");
		} while (!WIFSIGNALED(i) && !WIFEXITED(i));
	free(npath), free(nstr), free(path), free(nstr2);
	return (1);
}
