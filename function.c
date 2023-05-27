#include "simple_shell.h"
/**
 * _putchar - This is the function to print
 * @c: the character
 * Return: no zero
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _printf_c - this is the  function to print characters
 * @flist: this is the list of arguments
 * Return: no zero
 */
int _printf_c(va_list flist)
{
	char x;

	x = va_arg(flist, int);
	return (write(1, &x, 1));
}
/**
 * _printf_s - this is the function to print strings
 * @flist: thi is the list of arguments
 * Return: no zero
 */
int _printf_s(va_list flist)
{
	char *ptr = NULL, *_null = "(null)";
	unsigned int leng = 0;

	ptr = va_arg(flist, char *);
	if (ptr == NULL)
	{
		ptr = _null;
	}
	while (*ptr)
	{
		_putchar(*ptr);
		ptr++;
		leng++;
	}
	return (leng);
}
