#include "monty.h"

/**
 * _pstr - function that prints the string starting at the top of the stack.
 * @head: is the head of double list
 * @line_number: line number of opcode
 * Return: none
 */

void _pstr(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int i;
	(void)line_number;

	for (i = 0; current && current->n != 0 &&
				!(current->n > 127 || current->n < 0);
		 i++)
	{
		fprintf(stdout, "%c", current->n);
		current = current->next;
	}
	fprintf(stdout, "\n");
}
