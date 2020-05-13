#include "monty.h"

void ll_free(stack_t **my_stack)
{
	stack_t *aux;

	if (*my_stack == NULL)
		return;
	while (*stack != NULL)
	{
		aux = *my_stack;
		*my_stack = (*my_stack)->next;
		free(aux);
	}
}
