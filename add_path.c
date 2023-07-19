#include "shell.h"


void add_path(char *arg, char **argv)
{
	char *store, *arg2, *path, *value = NULL;
	char newpath[100];
	int i = 0;
	char *find = "PATH";
	struct stat check;
	int status;
	pid_t forkRV;

	arg2 = strdup(arg);

	while(environ[i])
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

	path = strtok(arg2, " ");
	
	value = strtok(store, ":");


	do
	{
		if (arg2[0] == '#')
			break;

		strcpy(newpath, value);

		strcat(newpath, "/");

		strcat(newpath, path);

		printf("PATH[%d] = %s\n", i, newpath);

		if (stat(newpath, &check) == 0)
		{
				printf("Found %s\n", newpath);
				sleep(3);
				forkRV = fork();
		

				if (forkRV == 0)
				{
					execve(newpath, argv, NULL);
				}

				else
				{
					printf("waiting\n");
					wait (&status);
					printf("Breaking now\n");
					break;
				}

		}

		i++;
		value = strtok(NULL, ":");
	}
	while(value);
	
	printf("%d\n", i);
}

/**
 * *_strstr - locates a substring
 * @haystack: string to search in
 * @needle: substring to look for
 *
 * Return: pointer to the beginning of the located substring
 * or NULL if the substring is not found
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
			return &(haystack[i + strlen(needle) + 1]);
	}
	
}
