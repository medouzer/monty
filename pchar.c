#include "monty.h"

/**
 * _pchar - function that prints the char to the top of the stack
 * @head: is the head of double list
 * @line_number: line number of opcode
 * Return: none
 */

void _pchar(stack_t **head, unsigned int line_number)
{
	if (!*head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n > 127 || (*head)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
