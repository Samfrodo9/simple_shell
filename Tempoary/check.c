#include "shell.h"

/**
 * check - a function to check and run files.
 *
 * Return: an integer.
 */

int check(char *str, char **buffer)
{
    int execRV = 100;

    if (str[0] == '#')
        return (0);
    else if (strcmp(str, "cd") == 0)
    {
        /* Call CD function */
    }
    else if (strcmp(str, "env") == 0)
    {
        /* Call env function */
    }
    else if (strcmp(str, "help") == 0)
    {
        /* call the exit function */
    }
    else if (strcmp(str, "exit") == 0)
    {
        /* Call the exit function */
    }
    else
        execRV = _execute(str, buffer);

    if (execRV == 1)
        return (0);
    else
    {
        add_path(str, buffer);
    }
}
