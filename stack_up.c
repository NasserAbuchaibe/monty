#include "monty.h"
int num;
/**
 * stack_up - pending
 * @file_m: file
 * Return: void
 */
void stack_up(char *file_m)
{
	stack_t *my_stack;
	char *token, *str;
	int line;

	str = r_file(file_m);

	my_stack = malloc(sizeof(char *));
	if (my_stack == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, "\n");

	for (line = 1; token != NULL; ++line)
	{
		clean_sp(&my_stack, line, token);
		token = strtok(NULL, "\n");
	}
	ll_free(&my_stack);
	free(my_stack);
}

/**
 * r_file - pending
 * @file: file to read
 * Return: pointer to the buffer
 */
char *r_file(char *file)
{
	char buff[MAX_BUFF + 1], *aux_buff;
	FILE *to_file;
	size_t size;

	to_file = fopen(file, "r");
	if (to_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	else
	{
		size = fread(buff, sizeof(char), MAX_BUFF, to_file);
		if (ferror(to_file))
		{
			fprintf(stderr, "Error: Can't open file %s\n", file);
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
	char *p_error;
	void (*func)(stack_t **stack, unsigned int l_num);

	while (isspace(*token))
		token++;
	if (strncmp(token, "push ", 5) == 0)
	{
		while (isalpha(*token))
			token++;
		
		token++;
		if (isdigit(*token) == 0)
		{
			fprintf(stderr,stderr,  "L%u: usage: push integer\n", line);
			ll_free(my_stack);
			free(my_stack);
			exit(EXIT_FAILURE);
		}
		if (token[0] != '-')
			num = atoi(token);
		else
			num = -1 * atoi(token);
		token = "push";
	}

	func = search_func(token);
	if (func != NULL)
	{
		func(my_stack, line);
	}
	else
	{
		p_error = strndup(token, 4);
		fprintf(stderr, "L%u: unknown instruction %s\n", line, p_error);
		ll_free(my_stack);
		free(my_stack);
		free(p_error);
		exit(EXIT_FAILURE);
	}
	
	
}


void (*search_func(char *command))(stack_t **my_stack, unsigned int l_num)
{
	int x = 0;
	instruction_t cmd[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};
	while (cmd[x].opcode != NULL)
	{
		if (strcmp(command, cmd[x].opcode) == 0)
			return (cmd[x].f);
		x++;
	}
	return (NULL);
}

int _len(char *command)
{
	int cont;

	for (cont = 0; isalpha(command[cont]) != 0; cont++)
	{
	}
	return (cont);
}
