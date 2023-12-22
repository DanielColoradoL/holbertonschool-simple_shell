#include "main.h"

void free_argv_array(char **argv);
char *search_path(const char *command);

/**
 * main - entry point
 *
 * Return: 0 if successful or non-zero if not
 */
int main(void)
{
	pid_t child_pid;
	char **argv, *buffer, *token, *path;
	int status;

	while (1)
	{
		buffer = _getline();
		token = strtok(buffer, "\n");
		while (token != NULL)
		{
			argv = _argv_array(token);

			if (argv[0] == NULL || strchr(argv[0], ' ') != NULL)
			{
				free(buffer);
				break;
			}
			if (strchr(argv[0], '/') == NULL)
			{
				if (strcmp(argv[0], "env") == 0)
				{
					_print_env();
					break;
				}
				else if (strcmp(argv[0], "exit") == 0)
				{
					free(buffer);
					free_argv_array(argv);
					exit(0);
				}
				path = search_path(argv[0]);
				if (path != NULL)
				{
					free(argv[0]);
					argv[0] = path;
				}
				else
				{
					fprintf(stderr, "./hsh: 1: %s: not found\n", token);
					free(buffer);
					free_argv_array(argv);
					break; /* Skip to the next iteration of the loop */
				}
				token = strtok(NULL, "\n");
			}
			child_pid = fork();
			if (child_pid == 0)
			{
				if (execve(argv[0], argv, NULL) == -1)
				{
					free(buffer);
					free_argv_array(argv);
					exit(1);
				}
			}
			if (child_pid != 0)
			{
				waitpid(child_pid, &status, 0);
				if (WIFEXITED(status))
				{
					if (!isatty(STDIN_FILENO) || WEXITSTATUS(status) == 0)
					{
						free(buffer);
						free_argv_array(argv);
						break;
					}
				}
			}
		}
	}
	return (0);
}

/**
 * free_argv_array - free array
 * @argv: array to be freed of memory
 *
 * Return: nothing
 */
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

/**
 * search_path - get the path for the command
 * @command: command input
 *
 * Return: new string containing full path
 */
char *search_path(const char *command)
{
	char *full_path;
	char *path_env = getenv("PATH");
	/* Duplicate the PATH string to avoid modifying the original */
	char *dir = strtok(strdup(path_env), ":");

	while (dir != NULL)
	{
		/* Build full path by concatenating the directory and the command */
		/* +2 for '/' and '\0' */
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		sprintf(full_path, "%s/%s", dir, command);
		/* Check if the file at the constructed path exists and is executable */
		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	return (NULL);
}
