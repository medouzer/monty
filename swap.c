#include "monty.h"

/**
 * _swap - this function is to swap the top two elements on the stack
 * @head: is the head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *tmp1;

	if (!*head || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	tmp1 = *head;
	tmp1->prev = tmp1->next;
	if ((*head)->next->next == NULL)
		tmp1->next = NULL;
	else
	{
		tmp1->next = tmp1->next->next;
		tmp1->next->prev = *head;
	}
	*head = tmp1->prev;
	(*head)->prev = NULL;
	(*head)->next = tmp1;
}
