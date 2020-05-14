#include "monty.h"

char *cleans(char *command)
{
	char *aux;
	int cont;

	for (cont = 0; isalpha(command[cont]) != 0; cont++)
	{
	}
	/*aux = malloc(sizeof(char) * cont); 
	if (aux == NULL)
		return (NULL);*/
	aux = strndup(command, cont);
	return (aux);
} 
