#include "monty.h"

int main()
{
	stack_t *stack;

	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);


	printall(&stack);
}
