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
