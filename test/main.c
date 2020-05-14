#include "monty.h"

int main(int argc, char **argv)
{
	stack_t *stack = malloc(sizeof(stack_t));

	
	push(&stack, 3);
	push(&stack, 3);
	push(&stack, 6);
	sub(&stack, 3);
	pall(&stack);
}
