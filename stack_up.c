#include "monty.h"
int num;
/**
 * stack_up - Tokenize instructions and data
 * @file_m: File with instructions
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
		fprintf(stderr, "Error: malloc failed\n");
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
 * r_file - open and buffer the command line
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

/**
 * clean_sp - get commands and data and send them the corresponding function
 * @my_stack: stack linked list
 * @token: instruction line
 * @line: line number to run
 * Return: void
 */
void clean_sp(stack_t **my_stack, int line, char *token)
{
	char *p_error;
	void (*func)(stack_t **stack, unsigned int l_num);

	while (isspace(*token))
		token++;
	if (token[0] == '#')
		return;
	if (strncmp(token, "push ", 4) == 0)
	{
		while (isalpha(*token))
			token++;
		while (isspace(*token))
			token++;
		if (isdigit(*token) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line);
			free(*my_stack);
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
		func(my_stack, line);
	else
	{
		p_error = strndup(token, 4);
		fprintf(stderr, "L%u: unknown instruction %s\n", line, p_error);
		free(*my_stack);
		free(p_error);
		exit(EXIT_FAILURE);
	}
}

/**
 * search_func- find the correct cfind the correct command according to the
 * instructin
 * @command: command identifier to search the struct
 * Return: function corresponding to that opcode
 */
void (*search_func(char *command))(stack_t **my_stack, unsigned int l_num)
{
	int x = 0;
	instruction_t cmd[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"nop", nop},
		{"mul", mul},
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
/**
 * _len - finds length of command
 * @command: string
 * Return: length
 */
int _len(char *command)
{
	int cont;

	for (cont = 0; isalpha(command[cont]) != 0; cont++)
	{
	}
	return (cont);
}
