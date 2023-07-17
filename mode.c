#include "shell.h"


/**
 * interactive - prints prompt.
 *
 * Return: void
 */

void interactive(void)
{
	char *str = NULL;
	char **cmd = NULL; /* Interactive command one to tokenize to command two */
	char **cmd2 = NULL; /* Interactive command two to pass to execve */
	int i = 0;
	char delim[] = {' ', '\n', NULL};

	prompt();
	str = _getline();
	cmd = _strtok(str, ";");/* Remember to free cmd */

	while (cmd[i])
	{	
		printf("%s\n", cmd[i]);
		i++;
	}

	while (cmd[i])
	{
		cmd2 = _strtok(cmd[i, delim);
		/* Add path */

		//execute; /* Check built-ins before executing */

	}
}


/**
 * non_interactive - prints prompt.
 *
 * Return: void
 */

void non_interactive(void)
{
	_putchar('\n');
}
