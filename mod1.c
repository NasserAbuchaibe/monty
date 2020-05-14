#include "monty.h"
/**
 * _mod - mod second top by top
 * @stack: stack
 * @line_num: line number
 */

void _mod(stack_t **stack, unsigned int line_num)
{
	int mod;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
		ll_free(stack);
		free(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		ll_free(stack);
		free(stack);
		exit(EXIT_FAILURE);
	}

	mod = ((*stack)->next)->n % (*stack)->n;

	(*stack)->next->n = mod;
	pop(stack, line_num);
}

