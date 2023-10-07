#include "shell.h"
char *_strdup(const char *jv)
{
char *ptr;
int len = 0, i;

if (jv == NULL)
{
return (NULL);
}

do
{
    len ++;
    jv ++;

}while (*jv != '\0');

jv = jv - len;
ptr = malloc(sizeof(char) * (len + 1));
if (ptr == NULL)
    return (NULL);
for ( i = 0; i <= len; i++)
ptr[i] = jv[i];
return (ptr);
}