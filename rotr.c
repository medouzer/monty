#include "monty.h"

/**
 * _rotr - this to rotates the stack to the bottom.
 * @head: is the head of double list
 * @line_number: line number of opcode
 * Return: none
 */

void _rotr(stack_t **head, unsigned int line_number)
{
	stack_t *last = *head;
	int i;

	if (!*head || (*head)->next == NULL)
		return;
	(void)line_number;
	for (i = 0; last; i++)
	{
		if (!last->next)
			break;
		last = last->next;
	}
	last->next = *head;
	last->prev->next = NULL;
	(*head)->prev = last;
	(*head) = last;
	last->prev = NULL;
}
