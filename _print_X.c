#include "simple_shell.h"
/**
 *_print_X - this will print a number in hexadecimal with uppercase letters
 *@flist: this is the list to search for the value to print
 *
 *Return: leng which is the length of the printed characters
 */
int _print_X(va_list flist)
{
	unsigned int base = 16, c = 1, leng = 0, j = 0;
	char z;
	unsigned int n = va_arg(flist, unsigned int);

	if (n < 16)
	{
		if (n >= 10)
			z = exchange_X(n), write(1, &z, 1);
		else
			z = n + '0', write(1, &z, 1);
	}
	else
	{
		while (c > 0)
		{
			if ((n / base) >= 16)
				base *= 16, c++;
			else
			{
				j = n / base;
				if (j > 10)
				{
					z = exchange_X(j), write(1, &z, 1);
					leng++, n %= base, base /= 16, c--;
				}
				else
				{
					z = (n / base) + '0', write(1, &z, 1);
					n %= base, base /= 16, leng++, c--;
				}
			}
		}
		if (n >= 10)
			z = exchange_X(n), write(1, &z, 1);
		else
			z = n + '0', write(1, &z, 1);
	}
	return (++leng);
}
/**
 *exchange_X - this will exchange values for letters in hexadecimal
 *@n: this is the number to search its parent in letrer
 *
 *Return: char equivalento to the digit in hexadecimal
 */
char exchange_X(unsigned int n)
{
	int k = 0;
	char *str = "ABCDEF";
	unsigned int str2[6] = {10, 11, 12, 13, 14, 15};

	while (k < 6)
	{
		if (str2[k] == n)
			return (str[k]);
		k++;
	}
	return (-1);
}
