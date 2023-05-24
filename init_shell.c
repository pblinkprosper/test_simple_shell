#include "shell.h"

/**
 * init_shell - this executes command passed to the shell
 * @cmd: the command to be executed
 * @cmd_type: check the command type
 *
 * Return: nothing
 */
void init_shell(char **cmd, int cmd_type)
{
	pid_t PID;
	int status;

	if (cmd_type == EXTR_CMD || cmd_type == PATH_CMD)
	{
		PID = fork();
		if (PID == 0)
			exec_cmd(cmd, cmd_type);
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
		exec_cmd(cmd, cmd_type);
}
