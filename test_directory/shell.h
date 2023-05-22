#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>

/* constants to be used in our program */
#define EXTR_CMD 1
#define INTR_CMD 2
#define PATH_CMD 3
#define INVL_CMD -1

extern int status;

/* string helper functions */
int _atoi(char *s);
char *_strcpy(char *dest, char *src);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _putchar(char ch);
void _puts(char *ch);
int _strcmp(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);
char *_strchr(char *s, char *c);
char **make_token(char *str_in, char *delim);
char *_strtok_r(char *str, char *delim, char **ptr);
void newline_handle(char *str);
unsigned int _strcspn(char *str1, char *str2);
unsigned int _strspn(char *s, char *accept);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* main program functions */
extern void init_shell(char **cmd, int cmd_type);

#endif
