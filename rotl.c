#include "monty.h"

/**
 * _rotl -  rotates the stack to the top.
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */

void _rotl(stack_t **head, unsigned int line_number)
{
	stack_t *last = *head;
	int i;

	if (!*head)
		return;
	(void)line_number;
	for (i = 0; last; i++)
	{
		if (!last->next)
			break;
		last = last->next;
	}
	last->next = *head;
	(*head)->prev = last;
	(*head) = (*head)->next;
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
}
