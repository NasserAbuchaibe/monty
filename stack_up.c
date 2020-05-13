#include "monty.h"
#define MAX_BUFF 10000

/**
 * stack_up - pending
 * @file_m: file
 * Return: void
 */
void stack_up(char *file_m)
{
	stack_t **my_stack;
	char *token, *str;
	int line;

	str = r_file(file_m);

	my_stack = malloc(sizeof(char *));
	if (my_stack  NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE)
	}

	token = strtok(str, "\n");

	for (line = 1; token != NULL; ++line)
	{
		clean_sp(my_stack, line, token);
		token(NULL, "\n");
	}
	ll_free(stack);
	free(stack);
}

/**
 * r_file - pending
 * @file: file to read
 * Return: pointer to the buffer
 */
char *r_file(char *file)
{
	char buff[MAX_BUFF + 1], aux_buff;
	FILE *to_file;
	size_t size;

	to_file = fopen(file, "r");
	if (to_file == NULL)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	else
	{
		size = fread(buff, sizeof(char), MAX_BUFF, to_file);
		if (ferror(to_file))
		{
			printf("Error: Can't open file %s\n", file);
			exit(EXIT_FAILURE);
		}
		else
			buff[size += 1] = '\0';
	}
	aux_buff = buff;
	fclose(to_file);
	return (aux_buff);
}

void clean_sp(stack_t **my_stack, int line, char *token)
{
	
}
