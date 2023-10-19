#include "monty.h"

/**
 * _pall -  prints all the elements of the stack
 * @head: is the head of the stack
 * @line_number: line number of opcode
 * Return: none
 */

void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	int i;

	(void)line_number;
	for (i = 0; current; i++)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
	fflush(stdout);
}
