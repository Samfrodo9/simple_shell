#include "shell.h"

/**
 * _strtok - strtok function implementation.
 *@str: str to tokenize.
 *@delim: delimeter.
 * Return: an array of strings.
 */

char **_strtok(char *str, char *delim)
{
	char **strings = NULL;
	char *temp, *copy = NULL;
	int i, j, num_tokens = 0;

	if (!str)
		return (NULL);
	copy = strdup(str);
	if (!copy)
		exit(EXIT_FAILURE);

	temp = strtok(copy, delim);
	while (temp != NULL) /* Count the no of tokens to allocate mem for string */
	{
		num_tokens++;
		temp = strtok(NULL, delim);
	}
	free(copy);
	strings = malloc(sizeof(char *) * (num_tokens + 1));
	/* Allocate memory for strings array */
	if (!strings)
		exit(EXIT_FAILURE);

	temp = strtok(str, delim); /* Tokenize the input string */
	while (temp != NULL)
	{
		strings[i] = strdup(temp);
		if (!strings[i])
		{
			for (j = 0; j < i; j++)
				free(strings[j]);
/* If memory allocation fails, free all previously allocated memory and exit */
			free(strings);
			exit(EXIT_FAILURE);
		}
		i++;
		temp = strtok(NULL, delim);
	}
	strings[i] = NULL;
	/* print_token(strings); */
	return (strings);
}

/**
 * free_tokens - Function to free the memory allocated by _strtok.
 * @tokens: tokens to free.
 */

void free_tokens(char **tokens)
{
	unsigned int i;

	if (!tokens)
		return;

	for (i = 0; tokens[i]; i++)
		free(tokens[i]);

	free(tokens);
}

/**
 * print_token - A function to print an array of strings
 * @token: strings to print
 */

void print_token(char **token)
{
	int i = 0;

	while (token[i])
	{
		printf("token[%d] = %s\n", i, token[i]);
		i++;
	}
}
