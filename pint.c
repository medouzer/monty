#include "monty.h"

/**
 * _pint - this function print the value on the top
 * @head: is the head of double list
 * @line_number: line number of opcode
 * Return: none
 */

void _pint(stack_t **head, unsigned int line_number)
{
	if (!*head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*head)->n);
	fflush(stdout);
}
