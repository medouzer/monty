#include "monty.h"

/**
 * _push -  add node to the stack
 * @head: is the head of the stack
 * @line_number: line number of opcode
 * Return: none
 */

void _push(stack_t **head, unsigned int line_number)
{
	stack_t *new, *last;
	int i = 0;

	(void)line_number;
	if (!head)
		return;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	new->n = datax.push_value;
	if (datax.mode == 0 || !*head)
	{
		if (*head)
		{
			new->next = *head;
			(*head)->prev = new;
		}
		else
			new->next = NULL;
		new->prev = NULL;
		*head = new;
	}
	else if (datax.mode == 1)
	{
		last = *head;
		for (i = 0; last; i++)
		{
			if (!last->next)
				break;
			last = last->next;
		}
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}
