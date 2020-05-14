#include "monty.h"

/**
 * cleans - clean space
 * @command: word with space
 * Return: clean word
 */

char *cleans(char *command)
{
	char *aux;
	int cont;

	for (cont = 0; isalpha(command[cont]) != 0; cont++)
	{
	}
	aux = strndup(command, cont);
	return (aux);
}
