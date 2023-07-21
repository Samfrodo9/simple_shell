#include "shell.h"

/**
 * exec_cd_dir - function to change the working directory
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
                /* No need to do change 'new_path' here, okay? */
                break;
        }
    }

    if (chdir(new_path) != 0)
    {
        perror("cd failed");
        return (-1);
    }

    current_path = getcwd(NULL, 0);
    setenv("PWD", current_path, 1);
    free(current_path);

    return (-1);

}


/**
 * exec_env - a function that prints environment variables
 * @str: argument vector containing the command and it argumments
 * Return: 0 on success
*/

int exec_env(char **str)
{

    int a = 0;
    char line = '\n';

    (void)(**str);

    while(environ[a])
    {
        write(STDIN_FILENO, environ[a], strlen(environ[a]));
        write(STDIN_FILENO, &line, 1);
        a++;
    }
    return (-1);
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
        return atoi(str[1]);
    }
    else
        return (0);
}