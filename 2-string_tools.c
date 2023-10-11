#include "shell.h"
/**
 * _strdup - duplicate given string
 * @jv: pointer of string to duplicate
 *
 * Return: pointer of duplicated string
 */
char *_strdup(const char *jv)
{
	char *ptr;
	int len = 0;
	int i;

	if (jv == NULL)
	{
		return (NULL);
	}
	do {
		len++;
		jv++;
	} while (*jv != '\0');
	jv = jv - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		ptr[i] = jv[i];
	return (ptr);
}
