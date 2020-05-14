#include "monty.h"

/**
 * main - get arguments
 * @argc: num of arguments
 * @argv: instructions and data to process
 * Return: 0
 */

int main(int argc, char **argv)
{
	stack_t *my_stack;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	my_stack = malloc(sizeof(stack_t));
	if (my_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	stack_up(argv[1], &my_stack);
	ll_free(&my_stack);
	free(my_stack);
	return (0);
}
