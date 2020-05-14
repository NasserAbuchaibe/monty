#include "monty.h"
/**
 * add - sum top and previous element
 * @stack: head of stack
 * @line_number : number of line readed
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if (n_nodes(aux) < 2)
	{
		fprintf(stderr, "<%d>: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (aux->next != NULL)
		aux = aux->next;

	aux->prev->n += aux->n;
	aux->prev->next = NULL;

	free(aux);
}
/**
 * n_nodes - get number of nodes in stack
 * @head: head of stack
 * Return: count of nodes
 */
int n_nodes(stack_t *head)
{
	int nodes = 0;

	while (head->next != NULL)
	{
		head = head->next;
		nodes++;
	}
	return (nodes);
}
