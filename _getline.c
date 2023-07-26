#include "shell.h"

/**
 * _getline - getline function implementation.
 *
 * Return: Returns the input received.
 */

char *_getline(void)
{
	char *receive = NULL;
	size_t n = 0;

	if (getline(&receive, &n, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(receive);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(receive);
			perror("Failed to read input");
			exit(EXIT_FAILURE);
		}
	}

	return (receive);
}
