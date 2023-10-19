#include "monty.h"

/**
 * free_stack -  function to free stack
 * @head: is the head of stack
 * Return: none
 */

void free_stack(stack_t *head)
{
	stack_t *nav, *nav2;

	nav = head;
	while (nav)
	{
		nav2 = nav->next;
		free(nav);
		nav = nav2;
	}
	datax.top = NULL;
	fclose(datax.mfile);
}
