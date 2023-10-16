#include "shell.h"
/**
 * _getenv - get environ variable
 * @keyvar: variable to search in env
 *
 * Return: PATH variable
 */
char *_getenv(char *keyvar)
{
	char *key_id, *key_value, *result, *env_temp;
	int i = 0;

	while (environ[i] != NULL)
	{
		env_temp = _strdup(environ[i]);
		key_id = strtok(env_temp, "=");
		if (_strcomp(key_id, keyvar) == 0)
		{
			key_value = strtok(NULL, "\n");
			result = _strdup(key_value);
			free(env_temp);
			return (result);
		}
		free(env_temp);
		env_temp = NULL;
		i++;
	}
	return (NULL);
}
