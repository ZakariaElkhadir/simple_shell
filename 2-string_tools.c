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
/**
 * cmd_build - build build the full path of command
 * @full_path: full path of command
 * @path_str: path command
 * @cmd_str: command
 *
 * Return: the full path of command
 */
char *cmd_build(char *full_path, char *path_str, char *cmd_str)
{
	int i = 0, j = 0;

	while (path_str[i] != '\0')
	{
		full_path[i] = path_str[i];
		i++;
	}
	full_path[i] = '/';
	i++;
	while (cmd_str[j] != '\0')
	{
		full_path[i] = cmd_str[j];
		i++;
		j++;
	}
	full_path[i] = '\0';
	return (full_path);
}
/**
 * _strcomp - compare two strings
 * @str1: pointer to 1st string
 * @str2: pointer to 2nd string
 *
 * Return: 0 in success
 */
int _strcomp(char *str1, char *str2)
{
	int result = 0, i = 0;

	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
		{
			result = str1[i] - str2[i];
			return (result);
		}
		i++;
	}
	return (result);
}
/**
 * _strlen - clalculte string length
 * @str: pointer to string
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int len = 0, i = 0;

	for (i = 0; str[i] != '\0'; i++)
		len++;
	return (len);
}
