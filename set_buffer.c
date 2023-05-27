#include "simple_shell.h"
/**
 * set_buffer - this will set the buffer with null character from aux_read position
 * @buffer: this is the string with line caught by read
 * @aux_read: this is the Number of bytes read by read
 * Return: void
 */
void set_buffer(char *buffer, ssize_t aux_read)
{
	ssize_t j = aux_read;

	while (buffer[j])
		buffer[j] = '\0', j++;
}
