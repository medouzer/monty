#include "monty.h"

/**
 * _mul - function that multiplies the second top element on the stack
 * @head: is the head of double list
 * @line_number: line number of opcode
 * Return: none
 */

void _mul(stack_t **head, unsigned int line_number)
{
	int value = 0;

	if (!*head || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*head)->n;
	_pop(&datax.top, datax.line_num);
	(*head)->n *= value;
}
