#include "header.h"
/**
 * str_len - THIS Finds the length of a string including the null character
 * @str: String to be measured
 * Return: j wich is the  length of the string
 */
int str_len(char *str)
{
	int j = 0;

	while (str[j])
		j++;

	return (j);
}
