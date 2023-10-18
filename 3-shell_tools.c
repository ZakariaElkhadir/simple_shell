#include "shell.h"
/**
 * freeArrayString - free memory of 2d array
 * @ar: pointer to 2d arr
 *
 * Return: nothing
 */
void freeArrayString(char **ar)
{
	int i;

	if (!ar)
		return;
	for (i = 0; ar[i]; i++)
	{
		free(ar[i]), ar[i] = NULL;
	}
	free(ar);
	ar = NULL;
}
/**
 * get_path_len - calculate command path length
 * @str1: command directory
 * @str2: command
 *
 * Return: lenght of command
 */
int get_path_len(char *str1, char *str2)
{
	int i = 0, j = 0, len = 0;

	while (str1[i] != '\0')
	{
		len++;
		i++;
	}
	while (str2[j] != '\0')
	{
		len++;
		j++;
	}
	return (len);
}
/**
 * int_converter - convert int to ASCII
 * @num: int to vonvert
 *
 * Return: char pointer
 */
char *int_converter(int num)
{
	char str[28], tmp;
	int i = 0, a = 0, z = 0;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (_strdup(str));
	}
	for (i = 0; num > 0; i++)
	{
		str[i] = (char)((num % 10) + '0');
		num = num / 10;
	}
	str[i] = '\0';
	z = i - 1;
	while (z > a)
	{
		tmp = str[a];
		str[a] = str[z];
		str[z] = tmp;
		a++;
		z--;
	}
	return (_strdup(str));
}
/**
 * error_print - print error not found cmd
 * @shell: name of program
 * @cmd: command name
 * @cmd_id: index of command
 *
 * Return: nothing
 */
void error_print(char *shell, char *cmd, int cmd_id)
{
	char *id;

	id = int_converter(cmd_id);

	write(STDERR_FILENO, shell, _strlen(shell));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, id, _strlen(id));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
	free(id);
}
