#include "simple_shell.h"
/**
 * _print_b - this will convert a decimal number to  base 2
 *  @flist: this is the list of arguments int
 *  Return: leng the length
 */
int _print_b(va_list flist)
{
	long int base = 2;
	long int n = (long int)va_arg(flist, unsigned int);
	int d = 1, leng = 0;
	char z = '\0';

	if (n < 2)
	{
		z = n == 0 ? '0' : '1';
		write(1, &z, 1);
	}
	else
	{
		while (d > 0)
		{
			if ((n / base) >= 2)
			{
				base *= 2;
				d++;
			}
			else
			{
				z = (n / base) + '0';
				write(1, &z, 1);
				n %= base;
				base /= 2;
				leng++;
				d--;
			}
		}
		z = n + '0';
		write(1, &z, 1);
	}
	return (++leng);
}
