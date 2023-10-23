#include "monty.h"

/**
 * _mode -  this to switch the mode queue/stack
 * @head: is the head of double list
 * @line_number: line number of opcode
 * Return: none
 */

void _mode(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	if (strcmp(datax.opcode, "queue") == 0)
		datax.mode = 1;
	else if (strcmp(datax.opcode, "stack") == 0)
		datax.mode = 0;
}
