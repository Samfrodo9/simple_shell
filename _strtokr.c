#include "shell.h"

/**
 * _strtokr - A function that tokenizes input gotten using read
 * @str: token to tokenize
 * @delim: the delimeter
 *
 * Return: The tokenize strings
 */

char **_strtokr(char *str, char *delim)
{
	char **strings = NULL;
	int num_tokens = 0, i = 0, j = 0;
	char *token, *pos, *copy = NULL;

	if (!str || !delim)
		return (NULL);

	copy = strdup(str);
	if (!copy)
		exit(EXIT_FAILURE);
	token = strtok(copy, delim);
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	free(copy);
	strings = malloc(sizeof(char *) * (num_tokens + 1));
	if (!strings)
		exit(EXIT_FAILURE);
	pos = str;

	while ((token = strtok(pos, delim)) != NULL)
	{
		if (*token != '\0')
		{
			strings[i] = strdup(token);
			if (!strings[i])
			{
				for (j = 0; j < i; j++)
					free(strings[j]);
				free(strings);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		pos = NULL; /* Set pos to NULL to continue tokenizing the original string */
	}
	strings[i] = NULL;
	return (strings);
}
