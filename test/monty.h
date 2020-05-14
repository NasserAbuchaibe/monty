#ifndef MONTY_H_
#define MONTY_H_

/** Libraries **/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
void add(stack_t **stack, unsigned int line_number);
int push(stack_t **head, int value); /** Pushing to stack **/
void pall(stack_t **head); /** print the stack full **/
void pint(stack_t **head); /** get the top address of the stack **/
void pop(stack_t **head, int line_n); /** pop top node in stack **/
int n_nodes(stack_t *head); /** get number of nodes in list **/
void swap(stack_t **head, int line_num);
void sub(stack_t **head, int line_num);
/** end Functions **/
#endif
