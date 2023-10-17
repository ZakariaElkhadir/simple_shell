#include "shell.h"
struct builtins bcmd[] = {
	{"exit", shell_exit},
	{"env", var_env},
	{NULL, NULL}
};
int builtin_check(char **cmd, int *st)
{
	int i = 0;

	while (bcmd[i].bc != NULL)
	{
		if (_strcomp(cmd[0], bcmd[i].bc) == 0)
		{
			bcmd[i].cmd_func(cmd, st);
			return (1);
		}
		i++;
	}
	return (0);
}
void shell_exit(char **cmd, int *st)
{
	freeArrayString(cmd);
	exit(*st);
}
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
