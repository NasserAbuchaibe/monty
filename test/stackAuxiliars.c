/*
 * Aux_Functions.c
 *
 *  Created on: 12/05/2020
 *      Author: deepzirox
 */

#include "monty.h"

void _div(stack_t **head, int line_number)
{
	stack_t *aux = *head;
	float res;

	if (n_nodes(aux) < 2)
	{
		fprintf(stderr,"<%d>: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (aux->next != NULL)
		aux = aux->next;

	res = aux->n /= aux->prev->n;
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
