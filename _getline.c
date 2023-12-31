#include "main.h"

/**
 * _getline - stores the user input in a
 *			nul terminated array.
 * Return: pointer to the beginning of the string
 *		 or NULL if the substring is not found
 */
char *_getline(void)
{
	char *buffer = NULL, *output = NULL;
	size_t size = 0;
	int chars, i;

	if (isatty(STDIN_FILENO))
		printf("$ ");
	chars = getline(&buffer, &size, stdin);
	/* If chars == -1 it means getline encounters an error or EOF*/
	if (chars == -1)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	output = malloc(sizeof(char) * chars);
	if (output == NULL)
	{
		free(buffer);
		return (NULL);
	}
	for (i = 0; i < chars; i++)
	{
		output[i] = buffer[i];
	}
	output[chars - 1] = '\0';
	free(buffer);
	return (output);
}
