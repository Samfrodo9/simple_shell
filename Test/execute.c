#include "shell.h"

int exec_vp(char *av[])
{
    if (av == NULL || av[0] == NULL || av[0][0] == '\0')
	{
		printf("Invalid command.\n");
        return (-1);
    }

    pid_t forkRV;
    int status;

    forkRV = fork();
    if (forkRV == 0)
	{
        if (execvp(av[0], av) == -1)
		{
            perror("Error");
			free_tokens(av);
            exit(EXIT_FAILURE);
        }
    }
	else if (forkRV < 0)
	{
        perror("Fork failed");
        return (-1);
    }
	else
	{
        do {
            if (waitpid(forkRV, &status, WUNTRACED) == -1)
			{
                /* waitpid failed */
                perror("Waitpid failed");
                return (-1);
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
	
		if (WIFEXITED(status))
		{
            return WEXITSTATUS(status);
        }
	}

    return (-1);
}
