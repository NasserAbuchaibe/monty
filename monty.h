#ifndef MONTY_H_
#define MONTY_H_

/** Libraries **/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFF 100000

extern int num;
/** end Libraries **/
/** Structures **/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/** end Structures **/
/** Functions **/
void stack_up(char *file_m);
char *r_file(char *file);
void clean_sp(stack_t **my_stack, int line, char *token);
void (*search_func(char *command))(stack_t **my_stack, unsigned int l_num);
int _len(char *command);
void ll_free(stack_t **my_stack);
/** Pushing to stack **/
void push(stack_t **stack, unsigned int line_number);
/** print the stack full **/
void pall(stack_t **stack, unsigned int line_number);
/** get the top address stack **/
void pint(stack_t **stack, unsigned int line_number);
/** pop top node in stack **/
void pop(stack_t **stack, unsigned int line_number);
/** get number of nodes in list **/
int n_nodes(stack_t *head);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **head, unsigned int line_num);
void nop(stack_t **head, unsigned int line_num);
/** end Functions **/
#endif
