#ifndef MONTY_H_
#define MONTY_H_

#define MAX_BUFF 10000

extern int num;

/** Libraries **/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
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
char *r_file(char *file) ;
void clean_sp(stack_t **my_stack, int line, char *token);
void (*search_func(char *command))(stack_t **my_stack, unsigned int l_num);
int _len(char *command);

int push(stack_t **top, int value); /** Pushing to stack **/
void pall(stack_t **head); /** print the stack full **/
stack_t *pint(stack_t **head); /** get the top address of the stack **/
int pop(stack_t **head, int line_n); /** pop top node in stack **/
int n_nodes(stack_t *head); /** get number of nodes in list **/
/** end Functions **/
#endif
