#include "main.h"

extern char **environ;

/**
 * _print_env - Prints the current environment variables
 * 
 * Return: Nothing
*/
void _print_env(void)
{
    int i;

    for (i = 0; environ[i] != NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
}
