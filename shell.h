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

extern char **environ;

int cmd_execute(char **cmd, char **argv);
char *read_command(void);
char *_strdup(const char *jv);
char **spliter(char *cmd_line);
void freeArrayString(char **ar);

#endif
