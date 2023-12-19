#include "main.h"

/**
 * main - entry point
 *
 * Return: 0 if successful or 1 if not
 */
int main(void)
{
	pid_t child_pid;
	char **argv, *buffer;

	while (1)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			buffer = _getline();
			if (buffer == NULL)
			{
				return (1);
			}
			argv = _argv_array(buffer);
			if (strcmp(argv[0], "./ppid") == 0)
			{
				printf("%d\n", getppid());
			}
			else
			{
				if (execve(argv[0], argv, NULL) == -1)
				{
					perror("Error:");
					return (1);
				}
			}
			return (0);
		}
		else
			wait(NULL);
			if (!isatty(STDIN_FILENO))
				break;
	}
	return (0);
}
