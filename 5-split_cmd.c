#include "shell.h"
/**
 * spliter - tokenize the command line
 * @cmd_line: pointer to command line
 *
 * Return: pointer of tokenized cmd
 */
char **spliter(char *cmd_line)
{
	char *tok = NULL;
	char *tmp_line = NULL;
	char del[] = " \t\n";
	char **command = NULL;
	int count = 0;
	int n = 0;

	if (!cmd_line)
		return (NULL);
	tmp_line = _strdup(cmd_line);
	tok = strtok(tmp_line, del);
	if (tok == NULL)
	{
		free(cmd_line), cmd_line = NULL;
		free(tmp_line), tmp_line = NULL;
		return (NULL);
	}
	while (tok)
	{
		count++;
		tok = strtok(NULL, del);
	}
	free(tmp_line), tmp_line = NULL;
	command = malloc(sizeof(char *) * (count + 1));
	if (!command)
	{
		free(cmd_line), cmd_line = NULL;
		return (NULL);
	}
	tok = strtok(cmd_line, del);
	do {
		command[n] = _strdup(tok);
		n++;
		tok = strtok(NULL, del);
	} while (tok);
	command[n] = NULL;
	free(cmd_line), cmd_line = NULL;
	return (command);
}
