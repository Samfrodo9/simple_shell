#include "shell.h"

/**
 * get_input - A function to read inputs from non-interactive mode
 *
 * Return: String read
 */

char *get_input(void)
{
	int buf_size = 1024, index = 0;
	char *input = malloc(sizeof(char) * buf_size);
	ssize_t bytesRead;
	char c;
	char *more_input = NULL;

	if (!input)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	while ((bytesRead = read(STDIN_FILENO, &c, 1)) > 0)
	{
		if (c == '\n' || c == EOF)
			break;
		input[index++] = c;

		if (index >= (buf_size - 1))
		{
			buf_size += 1024;


			more_input = realloc(input, buf_size);

			if (!more_input)
			{
				perror("Memory reallocation error");
				free(input);
				exit(EXIT_FAILURE);
			}
			input = more_input;
		}
	}

	terminate(bytesRead, input);

	input[index] = '\0'; /* I added a NULL Terminator */
	return (input);
}

/**
 * terminate - To check for EOF condition empty input condtions
 * @n: number of bytes read
 * @k: buffer being read
 */

void terminate(ssize_t n, char *k)
{
	if (n == -1)
	{
		perror("Error reading from stdin");
		free(k);
		exit(EXIT_FAILURE);
	}
	if (n == 0)
	{
		free(k);
		exit(EXIT_FAILURE);
	}
}

