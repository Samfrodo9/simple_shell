#include "shell.h"

/**
 * interactive - prints prompt.
 *
 * Return: void
 */

void interactive(void)
{
	char *stream = NULL;
	char *terminal = NULL; /* Interactive command one to tokenize to command two */
	char **str = NULL; /* Interactive command two to pass to execve */
	int control = -1;
	char delim[] = {' ', '\n'};

	do {
		prompt();
		stream = _getline(); /* command from keyboard */
		printf("Stream is %s\n", stream);
		terminal = strtok(stream, ";"); /* terminal = "ls -l /tmp" */
		printf("Terminal is %s\n", terminal);
		int i = 0;
		while(terminal)
		{
			/* str = {"ls",  */
			str = _strtok(terminal, delim); /* Return an array of strings */
			control = executeBuiltins(str);
			terminal = strtok(NULL, ";");
		}

		free(stream);
		free_tokens(str);
		if (control >= 0)
			exit(control);
	} while (control == -1);
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
