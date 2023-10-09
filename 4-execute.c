#include "shell.h"
int _execute(char **command, char **argv)
{
	pid_t son;
	int fc;

	son = fork();

	if (son == 0)
	{
		/*execute statment*/
		if (execve(command[0], command, environ) == -1)
		{
			perror(argv[0]);
			freeArrayString(command);
			exit(0);
		}

	}
	else
	{
		waitpid(son, &fc, 0);
		freeArrayString(command);
	}
	return (WEXITSTATUS(fc));
}
