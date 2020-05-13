#include "monty.h"

int main()
{
	stack_t *stack = malloc(sizeof(stack_t));

	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 6);
	pall(&stack);
	puts("==================");
	pop(&stack, 0);
	pop(&stack, 0);
	pop(&stack, 0);
	pop(&stack, 0);
	push(&stack, 200);
	push(&stack, 201);
	pall(&stack);


	return (EXIT_SUCCESS);
}
