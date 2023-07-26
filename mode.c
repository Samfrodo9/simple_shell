#include "shell.h"

char **_strtokr(char *str, char *delim);

/**
 * interactive - prints prompt.
 *
 * Return: void
 */

void interactive(void)
{
	char *stream = NULL;
	char *terminal = NULL; /* Interactive command oneto tokenize to command two */
	char **str = NULL; /* Interactive command two to pass to execve */
	int control = -1;
	/* char delim[] = {' ', '\n'}; */

	do {
		prompt();
		stream = _getline(); /* command from keyboard */
		terminal = strtok(stream, ";"); /* terminal = "ls -l /tmp" */

		while (terminal)
		{
			/* str = {"ls",  */
			str = _strtok(terminal, " \n"); /* Return an array of strings */
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
	char *stream = NULL;
	char *terminal = NULL; /* Non interactive command to tokenize */
	char **str = NULL; /* Non interactive command to pass to execve */
	int control = -1;
	/* char delim[] = {' ', '\n'}; */

	do {
		prompt();
		stream = get_input();
		/* printf("Input is %s\n", stream); */

		terminal = strtok(stream, ";");

		/* printf("First token is %s\n", terminal); */

		while (terminal)
		{
			str = _strtokr(terminal, " \n");
			control = executeBuiltins(str);
			terminal = strtok(NULL, ";");
		}

		/* printf(" I is %d\n", i); */

		free(stream);
		free_tokens(str);
		if (control >= 0)
			exit(control);
	} while (control == -1);
}
