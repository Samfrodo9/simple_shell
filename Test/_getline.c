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
		printf("Error");
		free(receive);
	}
	if (feof(stdin))
	{
		printf("Error 2");
		free(receive);
	}

	return (receive);
}
