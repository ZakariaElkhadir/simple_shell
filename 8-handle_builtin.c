#include "shell.h"
/**
 * builtin_check - check builtin cmd
 * @cmd: pointer to cmd line
 * @st: exit status
 *
 * Return: 1 on sucess or 0
 */
int builtin_check(char **cmd, int *st)
{
	char *builtin_cmd[] = {"exit", "env"};

	if (_strcomp(cmd[0], builtin_cmd[0]) == 0)
		shell_exit(cmd, st);
	else if (_strcomp(cmd[0], builtin_cmd[1]) == 0)
	{
		var_env(cmd, st);
		return (1);
	}
	return (0);
}
/**
 * shell_exit - exit shell func
 * @cmd: pointer to cmd
 * @st: exit status
 */
void shell_exit(char **cmd, int *st)
{
	freeArrayString(cmd);
	exit(*st);
}
/**
 * var_env - environ var func
 * @cmd: pointer to cmd line
 * @st: exit status
 */
void var_env(char **cmd, int *st)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	freeArrayString(cmd);
	(*st) = 0;
}
