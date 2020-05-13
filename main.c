#include "monty.h"

/**
 * main - get arguments
 * @argc: num of arguments
 * @argv: instructions and data to process
 * Return: 0
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stack_up(argv[1]);
	return (0);
}
