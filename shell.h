#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


void prompt(void);
int _putchar(char c);
void interactive(void);
void non_interactive(void);
char *_getline(void);
char **_strtok(char *str);
char *_strncat(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
void _puts(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

#endif
