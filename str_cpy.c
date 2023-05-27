#include "simple_shell.h"
/**
 * str_cpy - THIS copies the first bytes of source  src into destination dest and set the remaining bytes
 * of dest with the null character
 * @dest: The destination for bytes from src
 * @src: Source of the bytes
 * @bytes: The number of bytes to copy from src
 * Return: dest or NULL on failure
 */
char *str_cpy(char *dest, char *src, int bytes)
{
	int j = 0;

	dest = malloc(sizeof(char) * (bytes + 1));
	if (!dest)
		return (NULL);
	while (src[j])
		dest[j] = src[j], j++;
	dest[j] = '\0';
	return (dest);
}
