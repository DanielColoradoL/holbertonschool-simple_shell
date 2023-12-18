#include "main.h"

/**
 * _argv_array - stores the user input in a
 *			nul terminated array.
 * @inp_str: input string containing the arguments.
 * Return: double pointer to the beginning of the first
 *		 string or NULL if there is an error
 */
char **_argv_array(char *inp_str)
{
	char string[80], string_cp[80];
	char *sub_string;
	const char *s = " ";
	int i = 0, j = 0;
	char **array;

	strcpy(string, inp_str);
	strcpy(string_cp, string);
	sub_string = strtok(string, s);

	/* Let us know how many substrings are there */
	while (sub_string != NULL)
	{
		i++;
		sub_string = strtok(NULL, s);
	}

	array = malloc(sizeof(char *) * (i + 1));
	if (array == NULL)
		return (NULL);

	sub_string = strtok(string_cp, s);

	while (sub_string != NULL)
	{
		array[j] = strdup(sub_string);
		j++;
		sub_string = strtok(NULL, s);
	}
	array[j] = NULL;

	return (array);
}
