#include "monty.h"

/**
 * _div - function that divides the second top element ofi the stack
 * @head: is the head of double list
 * @line_number: line number of opcode
 * Return: none
 */

void _div(stack_t **head, unsigned int line_number)
{
	int value = 0;

	if (!*head || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*head)->n;
	_pop(&datax.top, datax.line_num);
	(*head)->n /= value;
}
