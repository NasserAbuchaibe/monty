#include "monty.h"
/**
 * _div - div second top by top
 * @stack: head of linked list
 * @line_number - number of line of the file readed
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int res;

	if (n_nodes(aux) < 2)
	{
		fprintf(stderr,"L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (aux->next != NULL)
		aux = aux->next;

	res = (float)aux->prev->n / (float)aux->n;
	res = (int)res;
	aux->prev->n = res;
	aux->prev->next = NULL;

	free(aux);
}



void add(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if (n_nodes(aux) < 2)
	{
		fprintf(stderr,"<%d>: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (aux->next != NULL)
		aux = aux->next;

	aux->prev->n += aux->n;
	aux->prev->next = NULL;

	free(aux);
}

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
