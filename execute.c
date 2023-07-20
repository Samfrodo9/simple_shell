#include "shell.h"


int _execute(char *path, char **argv)
{
	struct stat check;
	pid_t forkRV;
	int status;

	if (stat(path, &check) == 0)
	{
		printf("Found %s\n", path);
		sleep(3);

		forkRV = fork();
		if (forkRV == -1)
			perror("Error: ");

		if (forkRV == 0)
		{
			execve(path, argv, NULL);
		}

		else
		{
			printf("Executing command\n");
			wait(&status);
			printf("Finished executing\n");
			return (1);

		}
	}
	return (0);
}
