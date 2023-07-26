#include "shell.h"


/**
 * interactive - prints prompt ($ ).
 *
 * Return: void
 */

void interactive(void)
{
	char *str = NULL;
	char **cmd = NULL; /* Interactive command one to tokenize to command two */
	char **cmd2 = NULL; /* Interactive command two to pass to execve */
	int i = 0, j = 0;
	char delim[] = {' ', '\n'};

	prompt();
	str = _getline(); /* command from keyboard */
	cmd = _strtok(str, ";");/* Remember to free cmd */

	while (cmd[i]) /* printing out all the tokenized command from keyboard */
	{	
		printf("%s\n", cmd[i]);
		i++;
	}
	i = 0;
	while (cmd[i]) /* e.g "ls -l" "ls -l /tmp" are stored here */
	{
		cmd2 = _strtok(cmd[i], delim); /* e.g "ls" "-l" "/tmp" are stored here */
		/* Try to execute built ins first */
		/** _execute(cmd2[0], char **argv);

		printf("before calling addpath\n");
		printf("%s\n", cmd2[i]);
		Add path
		add_path(cmd2[i], cmd2); 
		*/
		check(cmd2[0], cmd2);
		i++;

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
