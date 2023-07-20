#include "shell.h"

/**
 * _getline - getline function.
 * 
 */

char *_getline(void)
{
	char *receive = NULL;
	size_t n = 0;

	if (getline(&receive, &n, stdin) == -1);
	{
		if (feof(stdin))
		{
			printf("%s\n", receive);
			free(receive);
			exit(EXIT_SUCCESS);
		}
		else
		{
			printf("%s\n", receive);
			free(receive);
			perror("Failed to read input");
			exit(EXIT_FAILURE);
		}
	}
	return (receive);
}