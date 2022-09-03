#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct glob_s - fd and its function
* @fd: The fd
* @line: The line
*/
typedef struct glob_s
{
	FILE *fd;
	char *line;
} glob_t;

extern glob_t global;
extern int value;

int main(int argc, char *argv[]);

/**_command.c */
void _command(char *argv);

/**functions_elem.c*/
stack_t *newnode(int n);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
int _isdigit(char *c);
void _pint(stack_t **stack, unsigned int line_number);

/**functions_elem2.c*/
void _swap(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void cleanStack(stack_t **stack);

/**_error.c */
void p_error(FILE *fd, char *line, stack_t *stack, int count);
void i_error(FILE *fd, char *line, stack_t *stack, char *count, int item);

/**free_dlistint*/
void free_dlistint(stack_t *stack);

/**get_*/
int get_(stack_t **stack, char *arg, char *item, int n);


#endif
