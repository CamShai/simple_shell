#include "simple_shell.h"
/**
 * add_node - this is a function that add node to save position to search env.
 * @head: this takes structure arguments pointer.
 * @setenv: aux to set env variable.
 * Return: the new node with position.
 */
node *add_node(node **head, char *setenv)
{
	node *new_node;

	new_node = malloc(sizeof(node));
	if (!new_node)
		return (NULL);
	new_node->setenv = setenv;
	if (!*head)
		*head = new_node, new_node->next = NULL;
	else
		new_node->next = *head, *head = new_node;

	return (new_node);
}
/**
 *free_listint - this frees a listint_t list
 *@head: this is the head of the list
 *Return: void
 */
void free_listint(node *head)
{
	node *aux;

	aux = head;
	while (head)
		head = head->next, free(aux->setenv), free(aux), aux = head;
}
/**
 *delete_nodein - this will delete the node at index of a listint_t
 *@head: this is the head of the list
 *@index: the indexindex
 *Return: -1 on operation failure or 1 if successful
 */
int delete_nodein(node **head, unsigned int index)
{
	unsigned int j = 0;
	node *aux, *aux2;

	aux = *head;
	if (!index && *head)
		*head = (*head)->next, free(aux->setenv), free(aux);
	else
	{
		while (aux && j < index - 1)
			aux = aux->next, j++;
		if (!aux)
			;
		else
		{
			aux2 = aux->next, aux->next = aux->next->next;
			free(aux2->setenv), free(aux2);
		}
	}

	return (!aux ? -1 : 1);
}
/**
 * owrenv - this is the fucntion that overwrite a variable existent.
 * @header: this is the pointer structure header.
 * @name: this is the pointer name variable to search.
 * @nvar: this is the pointer new variable to change.
 * Return: return nothing.
 */
void owrenv(ssh *header, char *name, char *nvar)
{
	char *envnew = NULL;
	int m = 0, n = 0, temp = 0;

	envnew = malloc(sizeof(char) * (str_len(name) + str_len(nvar) + 2));
	if (!envnew)
	{
		_printf("Error: can not allocate memory\n");
		exit(EXIT_FAILURE);
	}
	envnew[0] = '\0';
	m = _searchenv2(name);
	header->envp[m] = envnew, temp = m, m = 0;
	while (name[m])
		header->envp[temp][m] = name[m], m++;
	header->envp[temp][m] = '=', m++;
	while (nvar[n])
		header->envp[temp][m] = nvar[n], m++, n++;
	header->envp[temp][n] = '\0';
	header->head = add_node(&header->head, header->envp[temp]);
	temp++;
	header->envp[temp] = NULL;
}
/**
 * addenv - function that add enviroment variable.
 * @header: pointer structure header.
 * @name: name variable environment.
 * @nvar: name new variable env.
 * @envnew: aux new variable env.
 * Return: succes all good.
 */
int addenv(ssh *header, char *name, char *nvar, char *envnew)
{
	size_t m = 0, n = 0, temp = 0;

	envnew[0] = '\0';
	while (header->envp[m]) /* will search the end of envp */
		++m;
	header->envp[m] = envnew, temp = m, m = 0;
	while (name[m])
		header->envp[temp][m] = name[m], m++;
	header->envp[temp][m] = '=', m++;
	while (nvar[n])
		header->envp[temp][m] = nvar[n], m++, n++;
	header->envp[temp][m] = '\0';
	header->head = add_node(&header->head, header->envp[temp]);
	temp++;
	header->envp[temp] = NULL;
	return (EXIT_SUCCESS);
}
