#include <string.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>


extern char **environ;

char *_strstr(char *haystack, char *needle);

int main(int argc, char **argv)
{
	char *store = NULL;
	int i = 0;
	char *find = "PATH=";
	char *value;
	char variable[50];
	struct stat check;
	int status;
	pid_t forkRV;

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
	value = strtok(store, ":");
	while(value)
	{
		printf("PATH[%d] = %s\n", i, value);
		
		strcat(value, "/");
		strcat(value, argv[1]);
		if (stat(value, &check) == 0)
		{
			printf("FOund %s", value);
			sleep(5);
			forkRV = fork();

			if (forkRV == 0)
			{
				strcpy(argv[1], value);
				execve(value, argv ,NULL);
			}
			else
			{
				wait(&status);
				break;
			}
		}

	i++;
	value = strtok(NULL, ":");
	}	
	return (0);
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
			return &(haystack[i + strlen(needle)]);
	}
	return (NULL);
}
