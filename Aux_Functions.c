/*
 * Aux_Functions.c
 *
 *  Created on: 12/05/2020
 *      Author: deepzirox
 */

#include "monty.h"


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
