#include "simple_shell.h"
/**
 *_printf - this will print a specified format
 *@format: this is the format to print
 *Return: the length of the printed
 */
int _printf(const char *format, ...)
{
	function_t identifier_f[] = {{'c', _printf_c}, {'s', _printf_s},
	{'i', print_number}, {'d', print_number}, {'b', _print_b},
	{'o', _print_o}, {'u', _print_u}, {'x', _print_x},
	{'X', _print_X}, {'\0', NULL}};
	va_list flist;
	unsigned int len_printf = 0, p = 0, k = 0, flag = 0;
	char z = '\0';

	if (format == NULL || (format[p] == '%' && format[1] == '\0'))
		return (-1);
	va_start(flist, format);
	while (format[p])
	{
		for (; format[p] != '%' && format[p] != '\0'; p++)
		{
			z = format[p];
			len_printf += _putchar(z);
		}
		flag = p + 1;
		if (format[flag] == '%' && format[p])
			_putchar('%'), len_printf++, p += 2;
		else if (format[flag] == '\0')
			p++;
		else
		{
			for (k = 0; identifier_f[k].id && format[p]; k++)
			{
				if (identifier_f[k].id == format[flag])
				{
					len_printf += identifier_f[k].f(flist);
					p += 2;
					break;
				}
			}
		}
		if (identifier_f[k].id == '\0' && format[p])
			_putchar(format[p++]), len_printf++;
	}
	va_end(flist);
	return (len_printf);
}
