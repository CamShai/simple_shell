#include "simple_shell.h"
/**
 * _strlen - THIS will count the length to string *s
 * @str: pointer string.
 * Return: length.
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len])
		len++;
	return (len);
}
/**
 * _strncmp - This will compare strings and size
 * @s1: This is the first string pointer.
 * @s2: This is the second string pointer.
 * @n: This is the lenght of string to compare.
 * Return: integer value of characters.
 */
int _strncmp(char *s1, char *s2, int n)
{
	char stri1, stri2;

	while (n > 0)
	{
		stri1 = *s1++;
		stri2 = *s2++;
		if (stri1 == '\0' || stri1 != stri2)
			return (stri1 - stri2);
		n--;
	}
	return (stri1 - stri2);
}
/**
 * _strchr - This will locate character in a string
 * @str: string to compare.
 * @c: character to copare.
 * Return: pointer firs occurence success or NULL fail.
 */
char *_strchr(char *str, char c)
{
	char *ptr;

	if (str == NULL)
		return (NULL);
	for (ptr = str; *ptr; ptr++)
	{
		if (*ptr == c)
			return (ptr);
	}
	return (NULL);
}
/**
 * _unsetenv - This is the function that will delete the variable name from environment
 * @header: is the pointer structure.
 * @copy: save the copy buffer and allocate memory.
 * @token: double pointer take token.
 * Return: 0 on success or -1 error.
 */
int _unsetenv(char *copy, char **token, ssh *header)
{
	char **envi = NULL, *name = token[1];
	node *aux = header->head;
	int leng1 = 0, j = 0, leng2 = 0;

	(void)copy;
	if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	leng1 = str_len(name);
	envi = environ;
	while (*envi != NULL)
	{
		if (_strncmp(*envi, name, leng1) == 0 && (*envi)[leng1] == '=')
		{
			while (*envi != NULL)
			{
				while (aux)
				{
					leng2 = str_len(name);
					if (!_strncmp(aux->setenv, name, leng2))
					{
						delete_nodein(&header->head, j);
						break;
					}
					aux = aux->next, j++;
				}
				*envi = *(envi + 1);
				envi++;
			}
		}
		else
		{
			envi++;
		}
	}
	return (EXIT_SUCCESS);
}
