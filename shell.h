#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>

/* constants to be used in our program */
#define DELIM "\n\r\t\a "
#define BUFFER 1024

extern char **environ;

/* string helper functions */
int _atoi(char *s);
char *_strcpy(char *dest, char *src);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _putchar(char ch);
void _puts(char *ch);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *str);
char *_strchr(char *s, char *c);
char *_strtok_r(char *str, char *delim, char **ptr);
unsigned int _strcspn(char *str1, char *str2);
int _isdigit(int c);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strncmp(const char *s1, const char *s2, size_t n);
int _quit_atoi(char *str);

/* shell functions */
char **make_token(char *str_in, char *delim);
char **parse_cmd(char *cmd);
char *_getenv(char **env, char *str);
int handle_path(char **cmd, char **env);
int exec_cmd(char **args, char **env);
int check_cmd(char **str, char **env, char *nstr, char *path, char *npath);
int get_f(char **cmd, char **env);
int _env(char **name);
void exit_sh(char **arg);
char *read_line(void);
int exit_message(char **arg);
int _cd(char **arg);

/* main program functions */
extern void init_shell(char **cmd, int cmd_type);

#endif
