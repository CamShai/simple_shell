#include "simple_shell.h"
/**
 * str_cmp - THIS will compare if the first bytes of str2 are include in str
 * @str: THIS is first string to look into in
 * @str2: this is the second string to look for
 * @bytes: count num bytes.
 * Return: EXIT_SUCCES if str2 is contained in str or EXIT_FAILURE on failure
 */
ssize_t str_cmp(char *str, char *str2, int bytes)
{
	int j = 0;

	while (str[j] == str2[j] && j < bytes)
		j++;
	if (j == bytes)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
