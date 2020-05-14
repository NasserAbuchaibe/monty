#include "monty.h"

/**
 * swap - swap the value of two stacks
 * @stack: head of stack
 * @line_number : number of line readed
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int tmp;

	if (n_nodes(aux) < 2)
	{
		fprintf(stderr, "<%d>: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (aux->next != NULL)
	{
		aux = aux->next;
	}
	tmp = aux->n;
	aux->n = aux->prev->n;
	aux->prev->n = tmp;
}
/**
 * pop - pop top element
 * @stack: head of stack
 * @line_number : number of line readed
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;
	int popped;

	if (n_nodes(*stack) == 0)
	{
		fprintf(stderr, "<%d>: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;

	while (aux->next != NULL)
		aux = aux->next;

	popped = aux->n;
	aux->prev->next = NULL;
	free(aux);

}
/**
 * pint - print top element
 * @stack: head of stack
 * @line_number : number of line readed
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (n_nodes(top) == 0)
	{	/** Aca se debe imprimir el numero de linea que no puedo ejecutar pop **/
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (top->next != NULL)
	{
		top = top->next;
	}
	printf("%d\n", top->n);
}

/**
 * pall - print all stack
 * @stack: head of stack
 * @line_number : number of line readed
 */
void pall(stack_t **stack, unsigned int line_number)
{
	int c = 0;

	while ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		c++;
	}
	for (; c > 0; c--)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->prev;
	}
}
/**
 * push - push element to top
 * @stack: head of stack
 * @line_number : number of line readed
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack = malloc(sizeof(stack_t));
	stack_t *aux = *stack;

	if (*stack == NULL)
	{
		new_stack->prev = NULL;
		new_stack->next = NULL;
		new_stack->n = num;
		*stack = new_stack;
		return;
	}

	while (aux->next != NULL)
		aux = aux->next;

	new_stack->n = num;
	new_stack->next = NULL;
	new_stack->prev = aux;
	aux->next = new_stack;

}
