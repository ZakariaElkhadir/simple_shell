#include "shell.h"
/**
 * main - simple shell unix command line interpreter
 * @argv: pointer to arguments passed to prg
 * @argc: number of arguments passed to prg
 *
 * Return: exit statut of the shell
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0, cmd_id = 0;
	(void) argc;

	do {
		line = read_command();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 2);
			return (status);
		}
		cmd_id++;
		command = spliter(line);
		if (!command)
			continue;
		status = cmd_execute(command, argv, cmd_id);
	} while (1);

}
