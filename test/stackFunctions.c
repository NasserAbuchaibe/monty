#include "monty.h"


void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *head;
	int tmp;

	if (n_nodes(aux) < 2)
	{
		printf("<%d>: can't swap, stack too short\n", line_number);
		return;
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

	if (*head == NULL)
	{	/** Aca se debe imprimir el numero de linea que no puedo ejecutar pop **/
		printf("<%d>: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *head;

	while(aux->next != NULL)
		aux = aux->next;

	popped = aux->n;
	aux->prev->next = NULL;
	free(aux);

}

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *head;

	while (top->next != NULL)
	{
		top = top->next;
	}
	printf("%d\n", top->n);
}


void pall(stack_t **stack, unsigned int line_number)
{
	int c = 0;

	while ((*head)->next != NULL)
	{
		*head = (*head)->next;
		c++;
	}
	for (; c > 0; c--)
	{
		printf("%d\n", (*head)->n);
		*head = (*head)->prev;
	}
}


int push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack = malloc(sizeof(stack_t));
	stack_t *aux = *head;

	if (*head == NULL)
	{
		new_stack->prev = NULL;
		new_stack->next = NULL;
		new_stack->n = value;
		*head = new_stack;
		return (1);
	}

	while (aux->next != NULL)
		aux = aux->next;

	new_stack->n = value;
	new_stack->next = NULL;
	new_stack->prev = aux;
	aux->next = new_stack;

	return (0);
}