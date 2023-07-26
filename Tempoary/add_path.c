#include "shell.h"

/**
 * add_path - adds the path.
 *@arg: first argument from keyboard.
 *@argv: array of strings.
 *
 * Return: void
 */

void add_path(char *arg, char **argv)
{
	char *store, *arg2, *path, *value = NULL;
	char newpath[100];
	int i = 0;
	char *find = "PATH";
	int check = 100;

	arg2 = strdup(arg); /* Storing ls -l here */

	while(environ[i]) /* environment variable */
	{
		store = _strstr(environ[i], find);
		if (store)
			break;
		i++;
	}

	if (store != NULL)
		printf("Store = %s\n", store);
	else
		printf("%s not found\n", find);

	i = 0;

	path = strtok(arg2, " "); /* Tokenizing ls -l to give us ls only */

	value = strtok(store, ":"); /* Tokenizing PATH vvariable */


	do
	{
		if (arg2[0] == '#')
			break;

		strcpy(newpath, value);

		strcat(newpath, "/");

		strcat(newpath, path);

		printf("PATH[%d] = %s\n", i, newpath);

		check = _execute(newpath, argv);
		if (check == 1)
			break;

		i++;
		value = strtok(NULL, ":");
	}
	while(value);
	
	printf("%d\n", i);
}
