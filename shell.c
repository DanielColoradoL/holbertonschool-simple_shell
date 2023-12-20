#include "main.h"

void free_argv_array(char **argv);

/**
 * main - entry point
 *
 * Return: 0 if successful or 1 if not
 */
int main(void)
{
	pid_t child_pid;
	char **argv, *buffer, *token;
	int status;

	while (1)
	{
		buffer = _getline();
		token = strtok(buffer, "\n");
        while (token != NULL)
        {
			argv = _argv_array(token);
			if (strcmp(argv[0], "env") == 0)
				_print_env();
			else if (strcmp(argv[0], "./ppid") == 0)
				printf("%d\n", getppid());
			else if (strcmp(argv[0], "exit") == 0)
			{
				free(buffer);
				free_argv_array(argv);
				exit (0);
			}
			token = strtok(NULL, "\n");
			child_pid = fork();
			if (child_pid == 0)
			{
					if (execve(argv[0], argv, NULL) == -1)
					{
						exit (1);
					}
			}
			if (child_pid != 0)
			{
				waitpid(child_pid, &status, 0);
				if (WIFEXITED(status))
				{
					if (!isatty(STDIN_FILENO) || WEXITSTATUS(status) == 0)
						break;
				}
			}
		}
		free(buffer);
		free_argv_array(argv);
	}
	free_argv_array(argv);
	return (0);
}

void free_argv_array(char **argv)
{
    int i = 0;
    while (argv[i] != NULL)
    {
        free(argv[i]);
        i++;
    }
    free(argv);
}
