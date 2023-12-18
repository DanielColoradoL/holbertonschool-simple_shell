#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * main - entry point
 *
 * Return: 0 if successful or 1 if not
 */
int main(void)
{
	char *buffer, *argv[2];
	size_t full_path, bufsize = 32;
	pid_t child_pid = getpid();

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
		return (1);
	printf("#cisfun$ ");
	while (1)
	{
		child_pid = fork();
		if (child_pid == 0)
			break;
		wait(NULL);
	}
	if (child_pid == 0)
	{
		full_path = getline(&buffer, &bufsize, stdin);
		/* Remove the newline character from the end of the input */
		if (buffer[full_path - 1] == '\n')
			buffer[full_path - 1] = '\0';
		argv[0] = buffer;
		argv[1] = NULL;
		if (strcmp(buffer, "./ppid") == 0)
		{
			printf("%d\n", getppid());
		}
		else
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
				free(buffer);
				return (1);
			}
		}
	}
	free(buffer);
	return (0);
}
