#include "simple_shell.h"
/**
 *print_number - this will print an integer
 *@flist: this is the integer to be printed
 *
 *Return: no zero
 */
int print_number(va_list flist)
{
	int power = 10, x = 1, min = 0, leng = 0, k = va_arg(flist, int);

	if (k < 0)
	{
		if (k == INT_MIN)
		{
			min = 1;
			k += 1;
		}
		_putchar('-');
		leng++;
		k *= -1;
	}
	if (k >= 0 && k <= 9)
		;
	else
	{
		while (x > 0)
		{
			if ((k / power) >= 10)
			{
				power *= 10;
				x++;
			}
			else
			{
				_putchar((k / power) + '0');
				k %= power;
				power /= 10;
				leng++;
				x--;
			}
		}
	}
	if (min)
		k += 1;
	_putchar(k + '0');

	return (++leng);
}
