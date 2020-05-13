#include "monty.h"

int main(int argc, char **argv)
{
	stack_t *stack = malloc(sizeof(stack_t));

	push(&stack, 105);
	push(&stack, 104);
	push(&stack, 103);
	push(&stack, 102);
	push(&stack, 101);
	push(&stack, 100);
	pop(&stack, 0);
	pall(&stack);
}
