include "monty.h"

int main(int argc, char **argv)
{
	stack_t *stack = malloc(sizeof(stack_t));

	push(&stack, 1);
	push(&stack, 10);
	push(&stack, 10);
	add(&stack, 0);
	pall(&stack);
}
