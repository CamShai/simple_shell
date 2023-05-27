#include "simple_shell.h"
/**
 * free_malloc - this is the function that free malloc.
 * @str: pointer that travel to malloc.
 * Return: nothing.
 */
void free_malloc(char **str)
{
	unsigned int c = 0;

	if (str == NULL)
	{
		return;
	}
	else
	{
		while (str[c])
		{
			free(str[c]);
			c++;
		}
		if (str[c] == NULL)
		{
			free(str[c]);
		}
	}
	free(str);
}
