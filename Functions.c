#include "monty.h"

void printall(stack_t **head)
{
	int c = 0, i;
	while ((*head)->next != NULL)
	{
		*head = (*head)->next;
		c++;
	}
	for (; c >= 0; c--)
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
