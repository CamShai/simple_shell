#include "simple_shell.h"
/**
 * _searchenv - this takes THE pointer to an environment variable
 * @name: variable name.
 * Return: exist pointer to variable, or NULL.
 */
char *_searchenv(char *name)
{
	char **envi;
	int leng;

	envi = environ;
	leng = str_len(name);
	while (*envi != NULL)
	{
		if (_strncmp(*envi, name, leng) == 0)
			return (*envi);
		envi++;
	}
	return (NULL);
}
/**
 * _envset - tis adds or modify environment var.
 * @header: take the structure data.
 * Return: return the name of variable.
 */
int _envset(char *copy, char **tok, ssh *header)
{
	char *nvar = NULL, *name = NULL;
	char *envinew = NULL;
	int leng1 = 0, leng2 = 0;

	(void)copy;
	name = tok[1], nvar = tok[2];
	if (nvar == NULL || name == NULL) /* setenv hola=mundo */
	{
		return (-1);
	}
	leng1 = str_len(name), leng2 = str_len(nvar);
	if (_searchenv(name) == NULL)
	{
		envinew = malloc(sizeof(char) * (leng1 + leng2 + 2));
		if (!envinew)
		{
			free(envinew);
			_printf("Error: can not allocate memory\n");
			exit(EXIT_FAILURE);
		}
		if (!addenv(header, name, nvar, envinew))
		{
			return (EXIT_SUCCESS);
		}
	}
	else
	{
		if (nvar == NULL)
			;
		else
		{
			owrenv(header, name, nvar);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_SUCCESS);
}
/**
 * _searchenv2 -THIS  takes THE pointer to an environment variable
 * @name: is the variable name.
 * Return: an integer.
 */
int _searchenv2(char *name)
{
	char **envi;
	int leng = 0, j = 0;

	envi = environ;
	leng = str_len(name);
	while (envi[j] != NULL)
	{
		if (_strncmp(envi[j], name, leng) == 0)
			return (j);
		j++;
	}
	return (0);
}
