#include "simple_shell.h"
/**
 * compare_str - this will search for word PATH in environment
 * @str: string with environment.
 * @PATH: the string with word PATH.
 *Return: 1 if successful or 0 on failure
 */
int compare_str(char *str, char *PATH)
{
	while (*PATH && *str)
	{
		if (*PATH == *str)
			PATH++, str++;
		else
			return (0);
	}

	return (1);
}
/**
 * add_argv - this will add / plus command name to a ditectory (e.g. /bin ---> /bin/ls)
 * @argv: this is the command name
 * @str_tok: this is the directory
 * Return: pointer to the pathname of the command
 */
char *add_argv(char *argv, char *str_tok) /* argv = pwd buffer = "+/ls -la" */
{
	int c = 0, d = 0, leng1 = str_len(argv), leng2 = str_len(str_tok);
	char *buff;

	buff = malloc(sizeof(char *) * (leng1 + leng2 + 2));
	if (!buff)
	{
		free(buff);
		_printf("Error: can not allocate memory\n");
		exit(EXIT_FAILURE);
	}
	while (str_tok[c])
		buff[c] = str_tok[c], c++;
	buff[c] = '/', c++;
	while (argv[d])
	{
		buff[c + d] = argv[d], d++;
	}
	buff[c + d] = '\0';

	return (buff);

}
/**
 * count_env - this will count the number of environment variables
 * @envp: this is the array of strings with the enviroment variables
 * Return: the number of envorment variables
 */
int count_env(char **envp)
{
	int j = 0;

	while (envp[j])
		j++;

	return (j);
}
/**
 * cpy_dptr - this will copy a double pointer content to another double pointer
 * @dest: this is the first array - string.
 * @from: this is the second array - string.
 * Return: void nothing.
 */
void cpy_dptr(char **dest, char **from)
{
	int j = 0;

	while (from[j])
	{
		dest[j] = malloc(sizeof(char) * (strlen(from[j]) + 1));
		if (!dest[j])
		{
			free_malloc(dest);
			_printf("Error: can not allocate memory\n");
			exit(EXIT_FAILURE);
		}
		strcpy(dest[j], from[j]);
		j++;
	}
}
/**
 * copy_strtok - this is the copy strtok in aux.
 * @aux_strtok: these are the pointer strtok values.
 * Return: aux char *.
 */
char *copy_strtok(char *aux_strtok)
{
	int leng = 0, j = 0;
	char *aux;

	while (aux_strtok[leng] != '\0')
		leng++;
	aux = malloc(sizeof(char) * (leng + 1));
	if (!aux)
	{
		_printf("Error: can not allocate memory\n");
		exit(EXIT_FAILURE);
	}
	while (j < leng)
	{
		aux[j] = aux_strtok[j];
		j++;
	}
	aux[j] = '\0';
	return (aux);
}
/**
 * _PATH - this will search for a command in the PATH variable
 * @arguments: pointer past arguments.
 * @envp: this is the double pointer past the env variable.
 * Return: NULL or exit.
 */
char *_PATH(char *arguments, char **envp)
{
	int aux_stat_2 = 0, aux_comp = 0, number_env = 0, j = 0;
	char *PATH = "PATH=", *aux_stat = NULL, **aux_strtok = NULL;
	char **env = NULL;

	number_env = count_env(envp);
	env = malloc(sizeof(char *) * (number_env + 1));
	if (!env)
	{
		free_malloc(env);
		_printf("Error: can not allocate memory\n");
		exit(EXIT_FAILURE);
	}
	while (j < number_env + 1)
		env[j] = NULL, j++;
	cpy_dptr(env, envp);
	j = 0;
	while (env[j] != NULL)
	{
		aux_comp = compare_str(env[j], PATH);/* now it will Look for PATH in env */
		if (aux_comp == 1)
			break;
		j++;
	}
	/* We have env[j] = PATH */
	aux_strtok = str_tok(env[j], " =:"); /*it is ususally recommended to work with copy */
	j = 0;
	while (aux_strtok[j] != NULL)
	{
		/*  add /command return directory/command */
		aux_stat = add_argv(arguments, aux_strtok[j]);
		/* now it will look for directory/command */
		aux_stat_2 = access(aux_stat, X_OK);
		if (aux_stat_2 == 0)
		{
			free_malloc(aux_strtok);
			return (aux_stat);
		}
		j++;
		free(aux_stat);
	}
	free_malloc(aux_strtok);
	free_malloc(env);
	return (NULL);
}
