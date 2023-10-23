#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
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
 * struct data - is where the datat stored
 * @push_value: is the value to push 
 * @line_num: is the number of line of opcode
 * @opcode: is the opcode
 * @mfile: is the file to open
 * @top: is the the top of the stack
 * @mode: if 0 mean stack,else 1 mean queue
 * for the stack you push in the start
 * but for the queue you push at end
 */
typedef struct data
{
	int push_value;
	unsigned int line_num;
	char *opcode;
	FILE *mfile;
	stack_t *top;
	int mode;
} data;
data datax;

/*main.c*/
int main(int argc, char **argv);

/*exec.c*/
void exec(void);

void _pall(stack_t **head, unsigned int line_number);
void _push(stack_t **head, unsigned int line_number);
char *rm_spaces(char *str);
FILE *openfile(char *filename);
void verify_number(char *token);
void free_stack(stack_t *head);
size_t num_len(int num);
void _pint(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);
void _add(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);
void _sub(stack_t **head, unsigned int line_number);
void _div(stack_t **head, unsigned int line_number);
void _mul(stack_t **head, unsigned int line_number);
void _mod(stack_t **head, unsigned int line_number);
void _pchar(stack_t **head, unsigned int line_number);
void _pstr(stack_t **head, unsigned int line_number);
void _rotl(stack_t **head, unsigned int line_number);
void _rotr(stack_t **head, unsigned int line_number);
void _mode(stack_t **head, unsigned int line_number);


#endif
