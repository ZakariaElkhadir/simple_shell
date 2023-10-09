#include "shell.h"
void freeArrayString(char **ar)
{
	int i;

	if (!ar)
		return;

	for (i = 0; ar[i]; i++)
	{
		free(ar[i]), ar[i] = NULL;
	}
	free(ar), ar = NULL;

}
