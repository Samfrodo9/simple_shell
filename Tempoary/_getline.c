#include "shell.h"

/**
 * _getline - getline function.
 * 
 */

char *_getline(void)
{
	char *receive = NULL;
	size_t n = 10;
	ssize_t get_rv;

	get_rv = getline(&receive, &n, stdin);
	if (get_rv == -1)
	{
		perror("Error");
		free(receive);
	}
	if (feof(stdin))
	{
		perror("Error ");
		free(receive);
	}

	return (receive);
}
