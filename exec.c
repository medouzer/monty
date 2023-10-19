#include "monty.h"

/**
 * exec - is the function that execute the commande
 * Return: none
 */

void exec(void)
{
	instruction_t ins[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL},
	};
	int j = 0;

	for (j = 0; ins[j].opcode; j++)
	{
		if (strcmp(datax.opcode, ins[j].opcode) == 0)
		{
			ins[j].f(&datax.top, datax.line_num);
			break;
		}
	}
	if (!ins[j].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				datax.line_num, datax.opcode);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
}
