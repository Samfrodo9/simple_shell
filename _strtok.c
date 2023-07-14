#include "shell.h"

/**
 * _strtok - strtok function
 *
 * Return: an array of strings
 */

char **_strtok(char *str)
{
	char **strings = NULL;
	char *temp = NULL;

	int i = 0;
	
	printf("%s\n", str);

	strings = malloc(sizeof(char *) * (strlen(str) + 1));
	
	temp = strtok(str, ";");

	while(temp != NULL)
	{
		strings[i] = malloc(sizeof(char) * (strlen(temp) + 1));/* Define Strlen */
		strcpy(strings[i], temp); /* Handle Null terminating character */
		i++;
		temp = strtok(NULL, ";");
	}

	strings[i] = NULL;
	printf("%d\n", i);
	return (strings);
}
