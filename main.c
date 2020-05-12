#include "monty.h"

int main()
{
	stack_t *stack;

	push(&stack, 100);
	push(&stack, 50);
	push(&stack, 10);
	push(&stack, 500);
	push(&stack, 30);

	printall(&stack);
}
