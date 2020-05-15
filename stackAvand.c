#include "monty.h"
/**
 * pstr - print all character allocated in stack
 * @stack: head of linked list
 * @line_number: number of line in file
 */
void pstr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	int c = 0;
	int code = 0;

	while ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		c++;
	}
	for (; c > 0; c--)
	{
		code = (*stack)->n;
		if (code > 126 || code <= 0)
			break;
		putchar((char)code);
		*stack = (*stack)->prev;
	}
	putchar('\n');
}
/**
 * pchar - print character ascii
 * @stack: head of linked list
 * @line_number: number of line in file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	char code;

	if (n_nodes(aux) == 0 || stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (aux->next != NULL)
		aux = aux->next;

	code = (char)aux->n;
	if (aux->n > 126 || aux->n < 64)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(code);
	putchar('\n');
}
/**
 * _div - div second top by top
 * @stack: head of linked list
 * @line_number: number of line of the file readed
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int res;

	if (n_nodes(aux) < 2 || stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (aux->next != NULL)
		aux = aux->next;

	if (aux->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		ll_free(stack);
		exit(EXIT_FAILURE);
	}

	res = (float)aux->prev->n / (float)aux->n;
	res = (int)res;
	aux->prev->n = res;
	aux->prev->next = NULL;

	free(aux);
}
