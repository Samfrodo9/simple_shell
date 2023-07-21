#include "shell.h"

/**
* execute - executes a command
* @av: argument it takes
* Return: (-1)
*/

int execute(char *av[])
{
	pid_t forkRV;
	int status;

	if (av == NULL || av[0] == NULL || av[0][0] == '\0')
	{
		printf("Invalid command.\n");
		return (-1);
	}

	forkRV = fork();
	if (forkRV < 0)
	{
		perror("Fork failed");
		return (-1);
	}
	if (forkRV == 0)
	{
		if (execvp(av[0], av) == -1)
		{
			perror("Error");
			free_tokens(av);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			if (waitpid(forkRV, &status, WUNTRACED) == -1)
			{
				perror("Waitpid failed"); /* waitPID failed */
				return (-1);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		if (WIFEXITED(status))
		{
			return (-1); /* I'm supposed to return WIFEXITED(STATUS) here */
		}
	}
		return (-1);
	}
