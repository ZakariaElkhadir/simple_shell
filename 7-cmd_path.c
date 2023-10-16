#include "shell.h"
/**
 * get_cmd_path - get command path
 * @cmd: pointer to command
 *
 * Return: pointer to path of command
 */
char *get_cmd_path(char *cmd)
{
	char *cmd_path, *path_var, *path_dir;
	struct stat buf;
	int i = 0, len = 0;

	while (cmd[i] != '\0')
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &buf) == 0)
			{
				cmd_path = _strdup(cmd);
				return (cmd_path);
			}
			return (NULL);
		}
		i++;
	}
	path_var = _getenv("PATH");
	if (path_var == NULL)
		return (NULL);
	path_dir = strtok(path_var, ":");
	do {
		len = get_path_len(cmd, path_dir);
		cmd_path = malloc(sizeof(char *) * (len + 2));
		if (cmd_path != NULL)
		{
			cmd_build(cmd_path, path_dir, cmd);
			if (stat(cmd_path, &buf) == 0)
			{
				free(path_var);
				return (cmd_path);
			}
			free(cmd_path), cmd_path = NULL;
			path_dir = strtok(NULL, ":");
		}
	} while (path_dir);
	free(path_var);
	free(cmd_path);
	return (NULL);
}
