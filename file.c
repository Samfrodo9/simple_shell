#include "shell.h"

/**
 * _strstr - locates a substring
 * @haystack: string to search in
 * @needle: substring to look for
 *
 * Return: pointer to the beginning of
 * the located substring or NULL if not found
 */

char *_strstr(char *haystack, char *needle)
{
	int i, j;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}
		if (!needle[j])
			return (&(haystack[i + _strlen(needle) + 1]));
	}
}

/**
 * _puts - a function that prints to stdout
 * @str: input string to print
 * 
 * Return: a single character
*/

void putstream(char *str, int stream)
{
	while(*str != '\0')
	{
		write(stream, str, 1);
		str++;
	}
}
