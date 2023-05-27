#include "simple_shell.h"
/**
 * _error - this will print error message and exit with a number status
 * @s: this is the pointer to error message
 * Return: void
 */
void _error(char *s)
{
	write(STDERR_FILENO, s, str_len(s));
	exit(EXIT_FAILURE);
}
/**
 * _perror - this will check for a condition and print error message and exit with a
 * EXIT FAILURE
 * @aux: this is the condition to check
 * @argv: this is the name of the program
 * Return: void
 */
void _perror(int aux, const char *argv)
{
	if (aux == -1)
	{
		perror(argv);
		exit(EXIT_FAILURE);
	}
}
