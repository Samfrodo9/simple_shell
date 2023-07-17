#include "shell.h"

/**
 * _strtok - strtok function
 *
 * Return: an array of strings
 */

char **_strtok(char *str, char *delim)
{
	char **strings = NULL;
	char *temp = NULL;

	int i = 0;

	strings = malloc(sizeof(char *) * (_strlen(str) + 1));
	
	temp = strtok(str, delim);

	while(temp != NULL)
	{
		strings[i] = malloc(sizeof(char) * (_strlen(temp) + 1));
		_strcpy(strings[i], temp); /* Handle Null terminating character */
		i++;
		temp = strtok(NULL, delim);
	}

	strings[i] = NULL;
	return (strings);
}
