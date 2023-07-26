#include "shell.h"

/**
* executeBuiltins - a function to execute appropriate builtin commands
* @str: argument vector containing the command and it argumments
*
* Return: 0 if the command is a built-in and successfully executed
* , and -1 if not
*/


int executeBuiltins(char **str)
{
	command builtins[] = {
		{"cd", &exec_cd_dir},
		{"env", &exec_env},
		{"exit", &exec_exit},
		{NULL, NULL}
	};

unsigned int i = 0;

if (str[0] == NULL)
	return (-1);

while (builtins[i].name != NULL)
{
	if (strcmp(str[0], builtins[i].name) == 0)
		return (builtins[i].funct(str));
	i++;
}

	return (execute(str));
}
