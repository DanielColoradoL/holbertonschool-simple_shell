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
	char string[2046];
	char *sub_string;
	const char *s = " \t\n\r";
	int i = 0;
	char **array;


	strcpy(string, inp_str);
	sub_string = strtok(string, s);
	array = malloc(sizeof(char *) * i);
	if (array == NULL)
		return (NULL);
	/* Let us know how many substrings are there */
	while (sub_string != NULL)
	{
        array[i] = strdup(sub_string);
		printf("%s\n", array[i]);
        i++;
        sub_string = strtok(NULL, s);
	}
	return (array);
}
