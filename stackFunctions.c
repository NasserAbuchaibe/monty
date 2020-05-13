#include "monty.h"


void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int tmp;

	if (n_nodes(aux) < 2)
	{
		printf("<%d>: can't swap, stack too short\n", line_number);
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


void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;
	int popped;

	if (*stack == NULL)
	{	/** Aca se debe imprimir el numero de linea que no puedo ejecutar pop **/
		printf("<%d>: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *stack;

	while(aux->next != NULL)
		aux = aux->next;

	popped = aux->n;
	aux->prev->next = NULL;
	free(aux);

}

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	while (top->next != NULL)
	{
		top = top->next;
	}
	printf("%d\n", top->n);
}


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
