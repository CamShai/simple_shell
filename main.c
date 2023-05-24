#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - this is the main function.
 * @argc :is the argument count.
 * @argv : argument vector.
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *prompt = ("$");
	char *line = NULL, *line_copy = NULL;
	char *token;
	size_t buffersize = 0;
	ssize_t input_length;
	int j;
	int counter_token = 0;
	(void)argc;
	
	while (1)
	{
		printf("%s", prompt);
		input_length = getline(&line, &buffersize, stdin);

		if (input_length == -1)
		{
			printf("exiting shell .1.2.3.\n");
			return (-1);
		}
		line_copy = malloc(sizeof(char) * input_length);
		if (line_copy == NULL)
		{
			perror("there is memory allocation error");
			return (-1);
		}
		strcpy(line_copy, line);
		token = strtok(line, TOKEN_DELIM);
		while (token != NULL)
		{
			counter_token++;
			token = strtok(NULL, TOKEN_DELIM);
		}
		counter_token++;
		argv = malloc(sizeof(char *) * counter_token);
		token = strtok(line_copy, TOKEN_DELIM);
		for (j = 0; token != NULL; j++)
		{
			argv[j] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[j], token);
			token = strtok(NULL, TOKEN_DELIM);
		}
		free(line_copy);
		free(line);
	}
	return (0);
}
