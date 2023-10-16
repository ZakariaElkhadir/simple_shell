#include "shell.h"
/**
 * cmd_execute - execute the command line
 * @cmd: command line to execute
 * @argv: program arguments
 * @cmd_id: status of command
 *
 * Return: execute statut
 */
int cmd_execute(char **cmd, char **argv, int cmd_id)
{
	char *cmd_path;
	pid_t son;
	int fc;

	cmd_path = get_cmd_path(cmd[0]);
	if (cmd_path == NULL)
	{
		error_print(argv[0], cmd[0], cmd_id);
		freeArrayString(cmd);
		return (127);
	}
	son = fork();
	if (son == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			freeArrayString(cmd);
			free(cmd_path);
		}
	}
	else
	{
		waitpid(son, &fc, 0);
		freeArrayString(cmd);
		free(cmd_path);
	}
	return (WEXITSTATUS(fc));
}
