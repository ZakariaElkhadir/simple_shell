#ifndef _SHELL_S_H
#define _SHELL_S_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <errno.h>

/*int main (int ac, char **argv);*/
char *read_command(void);
char *_strdup(const char *jv);
char **token(char *line);

#endif
