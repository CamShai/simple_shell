#include "simple_shell.h"
/**
 *add_nodeint_end - this will add a new node at the end of a listint_t list
 *@head: this is the head of the list
 *@command: data
 *
 *Return: new_node address of the new created node
 */
commands *add_node_end(commands **head, char **command)
{
	commands *new_node;
	commands *aux;

	new_node = malloc(sizeof(commands));
	if (!new_node)
		return (NULL);
	new_node->split_command = command;
	new_node->next = NULL;
	if (!*head)
		*head = new_node;
	else
	{
		aux = *head;
		while (aux->next)
			aux = aux->next;
		aux->next = new_node;
	}

	return (new_node);
}
/**
 * split_buffer - this will allocate memory to buffer and separe words.
 * @header: pointer arguments structure.
 * Return: arguments (double pointer).
 */
void split_buffer(ssh *header)
{
	char delimiter[] = "\n", delimiter2[] = " \t", **aux = NULL;
	int j = 0;

	header->arguments = str_tok(header->buffer, delimiter);
	while (header->arguments[j])
	{
		if (header->arguments[j][0] != '\0')
		{
			aux = str_tok(header->arguments[j], delimiter2);
			add_node_end(&header->head_cmd, aux);
		}
		j++;
	}
}
/**
 * check_exit - this will check if the secon argument passed to exit command is a string
 * with no digits
 * @token: second argument of the exit command
 * Return: 0 if the string have only digits or 1 if not
 */
int check_exit(char *token)
{
	int j = 0;

	if (token[j] == '-')
		j++;
	while (token[j])
	{
		if (token[j] >= '0' && token[j] <= '9')
			j++;
		else
			return (1);
	}

	return (0);
}
/**
 * exit_ - this is the function with validation exit.
 * @header: this will take arguments structure.
 * @aux: this willtake auxiliary pointer array.
 * @aux2: this will take second  auxiliary pointer array2.
 * Return: integer 0 or exit success.
 */
int exit_(char *copy, char **token, ssh *header)
{
	int EXIT_STATUS = 0, flag_char = 0;

	if (token[1])
	{
		EXIT_STATUS = _atoi(token[1]);
		flag_char = check_exit(token[1]);
		if (flag_char == 1 || EXIT_STATUS < 0)
		{
			_printf("%s: exit: Illegal number: %s\n",
				header->argv[0], token[1]);
			free_malloc(token), free(copy);
			return (2);
		}
	}
	free(header->buffer), free_malloc(token), free(copy);
	free_malloc(header->arguments), free(header->OLD_WD), free_PWD(header);
	free_listint(header->head), free_commands(header);
	free(copy), free_malloc(token), free(header);
	exit(EXIT_STATUS);
}
/**
 * _env - this will take enviromen variable by the structure
 * @header: is the pointer structure values.
 * Return: 0 if successful.
 */
int _env(char *copy, char **token, ssh *header)
{
	int j = 0;

	(void)copy;
	(void)token;
	if (token[1] == NULL)
	{
		while (header->envp[j])
			_printf("%s\n", header->envp[j]), j++;
	}

	return (0);
}
/**
 * check_buffer - this wll check the content buffer (words or NULL, etc.)
 * @buffer: this is the buffer
 * @header: this is te pointer to the structure.
 * Return: 1 or 0 if successful or failed respectively.
 */
int check_buffer(char *buffer, ssh *header)
{
	comparison_id identifiers[] = {{"exit", exit_}, {"env", _env},
	{"cd", _cd}, {"setenv", _envset},
	{"unsetenv", _unsetenv}, {NULL, NULL}};
	char **token = NULL, *copy = NULL;
	int j = 0, aux = 1;

	copy = str_cpy(copy, buffer, str_len(buffer));
	token = str_tok(copy, " \n\t\r\b\v\f"); /* copy of split buffer */
	if (token[0] == NULL)
	{
		free_malloc(token), free(copy);
		return (0);
	}
	while (identifiers[j].comp)
	{
		if (!str_cmp(identifiers[j].comp, token[0], str_len(token[0])))
		{
			aux = identifiers[j].function_int(copy, token, header);
			break;
		}
		j++;
	}
	free_malloc(token), free(copy);
	return (aux);
}
