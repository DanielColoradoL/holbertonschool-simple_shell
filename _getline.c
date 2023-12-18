#include "main.h"

/**
 * _getline - stores the user input in a
 *			nul terminated array.
 * Return: pointer to the beginning of the string
 *		 or NULL if the substring is not found
 */
char *_getline(void)
{
	char *buffer, *output;
	size_t size = 80;
	int chars, i;

	buffer = malloc(sizeof(char) * size);
	if (buffer == NULL)
		return (NULL);

	printf("$ ");
	chars = getline(&buffer, &size, stdin);

	/* If chars == -1 it means error from getline */
	if (chars == -1)
	{
		free(buffer);
		return (NULL);
	}

	output = malloc(sizeof(char) * chars);
	if (output == NULL)
		return (NULL);

	for (i = 0; i < chars; i++)
	{
		if (i == chars - 1)
			output[i] = 0;
		else
			output[i] = buffer[i];
	}

	free(buffer);
	return (output);
}
