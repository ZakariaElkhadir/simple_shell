#include "shell.h"
/**
 * cmd_execute - execute the command line
 * @cmd: command line to execute
 * @argv: program arguments
 *
 * Return: execute statut
 */
int cmd_execute(char **cmd, char **argv)
{
	pid_t son;
	int fc;

	son = fork();
	if (son == -1)
	{
		perror(argv[0]);
		freeArrayString(cmd);
		exit(0);
	}
	if (son == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(argv[0]);
			freeArrayString(cmd);
			exit(0);
		}

	}
	else
	{
		if (waitpid(son, &fc, 0) == -1)
		{
			perror(argv[0]);
			freeArrayString(cmd);
			exit(0);
		}
		freeArrayString(cmd);
	}
	return (WEXITSTATUS(fc));
}
