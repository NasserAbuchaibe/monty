include "monty.h"

int main(int argc, char **argv)
{
	stack_t *stack = malloc(sizeof(stack_t));

	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	pall(&stack);
	swap(&stack, 404);
	pall(&stack);
}
