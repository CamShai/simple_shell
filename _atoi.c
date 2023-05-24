#include "simple_shell.h"
/**
 *_atoi -this  converts the string to an integer
 *@s:is the pointer to a string of characters
 *
 *Return: integer
 */
int _atoi(char *s)
{
	int sign, num, j;

	sign = num = 0;
	for (j = 0; s[j] != '\0'; j++)
	{
		if (s[j] == '-')
			sign++;
		else if (s[j] >= '0' && s[j] <= '9')
			num = num * 10 + (s[j] - '0');
		else if (num > 0)
			break;
	}
	if (sign % 2 == 0)
		return (num);
	else
		return (num *= -1);
}
