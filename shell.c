#include "shell.h"

/**
 * main - prints prompt ($ ).
 *
 * Return: Always 0.
 */

int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
		interactive();
	else
		non_interactive();

	return (0);
}
