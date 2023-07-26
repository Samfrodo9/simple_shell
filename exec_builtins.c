#include "shell.h"

/**
 * exec_cd_dir - a function that changes the working directory
 * @argv: arguments
 *
 * Return: 1 on success, 0 on failure
*/

int exec_cd_dir(char **argv)
{
	char *new_path = argv[1];
	char *current_path;

	if (new_path == NULL)
		new_path = getenv("HOME");
	else
	{
		switch (new_path[0])
		{
			case '~':
				new_path = getenv("HOME");
				break;
			case '-':
				new_path = getenv("OLDPWD");
				break;
			default:
				/* No need to do change 'new_path' here, */
				break;
		}
	}

		if (chdir(new_path) != 0)
		{
			perror("cd failed");
				return (1);
		}

		current_path = getcwd(NULL, 0);
		setenv("PWD", current_path, 1);
		free(current_path);

		return (0);
}


/**
 * exec_env - a function that prints environment variables
 * @str: The string
 *
 * Return: 0 on success
*/

int exec_env(char **str)
{
	int i = 0;

	(void)str;

	while (environ[i])
	{
		_puts(environ[i]);
		i++;
	}

	return (0);
}


/**
* exec_exit - A function that terminates a process
* @str: argument
*
* Return: 0 on success
*/

int exec_exit(char **str)
{
	if (str[1])
	{
		return (atoi(str[1]));
	}
	else
		return (0);
}

/**
 * exec_setenv - Initialize a new environment variable or modify anexisting one
 * @str: Argument vector containing the commands
 *
 * Return: 0 on success and 1 on failure
 */
int exec_setenv(char **str)
{
	char *variable, *value;

	if (str[1] == NULL || str[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (1);
	}

	variable = str[1];
	value = str[2];

	if (setenv(variable, value, 1) != 0)
	{
		perror("setenv");
		return (1);
	}

	return (0);
}


/**
 * exec_unsetenv - Remove an environment variable
 * @str: Argument vector containing the commands
 *
 * Return: 0 on success and 1 on failure
 */


int exec_unsetenv(char **str)
{
	if (str[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return (1);
	}

	if (unsetenv(str[1]) != 0)
	{
		perror("unsetenv");
		return (1);
	}
	return (0);
}

