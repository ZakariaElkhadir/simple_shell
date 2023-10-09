#ifndef _SHELL_S_H
#define _SHELL_S_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <errno.h>

int _execute(char **command, char **argv);
extern char **environ;
char *read_command(void);
char *_strdup(const char *jv);
char **token(char *line);
void freeArrayString(char **ar);

#endif
