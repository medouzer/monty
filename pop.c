#include "monty.h"

/**
 * _pop - is th function to remove the top element on the stack
 * @head: is the head of double list
 * @line_number: line number of opcode
 * Return: none
 */

void _pop(stack_t **head, unsigned int line_number)
{

	if (!*head)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		*head = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
}
