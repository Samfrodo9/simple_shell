#include "shell.h"


/**
 * interactive - prints prompt.
 *
 * Return: void
 */

void interactive(void)
{
	char *str = NULL;
	char **cmd = NULL;
	int i = 0;

	prompt();
	str = _getline();
	cmd = _strtok(str);/* free cmd */

	while (cmd[i])
	{	
		printf("%s\n", cmd[i]);
		i++;
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
