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
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (aux->next != NULL)
		aux = aux->next;

	aux->prev->n += aux->n;
	aux->prev->next = NULL;

	free(aux);
}


/**
 * sub - sub top and previous element
 * @head: head of stack
 * @line_num : number of line readed
 */
void sub(stack_t **head, int line_num)
{
	stack_t *aux = *head;

	if (n_nodes(aux) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	while (aux->next != NULL)
		aux = aux->next;

	aux->prev->n -= aux->n;
	aux->prev->next = NULL;

	free(aux);
}


/**
 * nop - doesnt do anything.
 * @head: head of stack
 * @line_num: number of line readed
 */
void nop(__attribute__ ((unused))stack_t **head,
		__attribute__ ((unused)) unsigned int line_num)
{
	;
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
