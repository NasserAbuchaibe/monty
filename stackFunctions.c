#include "monty.h"



int pop(stack_t **head, int line_num)
{
	stack_t *aux;
	int popped;

	if (*head == NULL)
	{	/** Aca se debe imprimir el numero de linea que no puedo ejecutar pop **/
		printf("<%d>: can't pop an empty stack", line_num);
		exit(EXIT_FAILURE);
	}
	aux = *head;

	while(aux->next != NULL)
		aux = aux->next;

	popped = aux->n;
	aux->prev->next = NULL;
	free(aux);

	return (popped);
}

stack_t *pint(stack_t **head)
{
	stack_t *top = *head;

	while (top->next != NULL)
	{
		top = top->next;
	}
	printf("%d\n", top->n);
	return (top);
}


void pall(stack_t **head)
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


int push(stack_t **head, int value)
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
