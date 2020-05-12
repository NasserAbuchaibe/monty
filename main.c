#include "monty.h"

int main()
{
	stack_t *stack = malloc(sizeof(stack_t));

	push(&stack, 1);
	pint(&stack);
	push(&stack, 2);
	pint(&stack);
	push(&stack, 3);
	pint(&stack);
	puts("==================");
	pall(&stack);

	return (EXIT_SUCCESS);
}
