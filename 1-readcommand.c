#include "shell.h"
/**
 * read_command - read command from stdin
 *
 * Return: pointer to command line
 */
char *read_command(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	if (isatty(STDIN_FILENO))
		write(STDERR_FILENO, "$ ", 2);
	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
