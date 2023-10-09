#include "shell.h"
char **token(char *line)
{
	char *tok = NULL;
	char *tmp = NULL;
	char del[] = " \t\n";
	char **command = NULL;
	int count = 0;
	int n = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);
	tok = strtok(tmp, del);
	if (tok == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (tok)
	{
		count++;
		tok = strtok(NULL, del);
	}
	free(tmp), tmp = NULL;
	command = malloc(sizeof(char *) * (count + 1));
	if (!command)
	{
		free(line), line = NULL;
		return (NULL);
	}
	tok = strtok(line, del);
	do {
		command[n] = _strdup(tok);
		n++;
		tok = strtok(NULL, del);
	} while (tok);
	command[n] = NULL;
	free(line), line = NULL;
	return (command);
}
