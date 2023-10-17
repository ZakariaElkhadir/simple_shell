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


struct builtins
{
	char *bc;
	void (*cmd_func)(char **cmd, int *st);
};



extern char **environ;
extern struct builtins bcmd[];

int cmd_execute(char **cmd, char **argv, int cmd_id);
char *read_command(void);
char **spliter(char *cmd_line);
char *get_cmd_path(char *cmd);
char *_getenv(char *keyvar);

void freeArrayString(char **ar);
int get_path_len(char *str1, char *str2);
char *int_converter(int num);
void error_print(char *shell, char *cmd, int cmd_id);

char *_strdup(const char *jv);
char *cmd_build(char *full_path, char *path_str, char *cmd_str);
int _strlen(char *str);
int _strcomp(char *str1, char *str2);

int builtin_check(char **cmd, int *st);
void shell_exit(char **cmd, int *st);
void var_env(char **cmd, int *st);

#endif
