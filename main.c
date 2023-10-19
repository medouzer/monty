#include "monty.h"

/**
 * main -  is the main off the programe
 * @argc: is the arg passed into functions
 * @argv: is the number of arg
 * Return: the number lentgh
 */
int main(int argc, char **argv)
{
	char line[100], *token;
	int i = 0;

	datax.mode = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	datax.mfile = openfile(argv[1]);
	while (fgets(line, sizeof(line), datax.mfile) != NULL)
	{
		if (strlen(rm_spaces(line)) < 3 || rm_spaces(line)[0] == '#')
		{
			datax.line_num++;
			continue;
		}
		datax.line_num++;
		token = strtok(line, " \n");
		for (i = 0; token != NULL && i < 2; i++)
		{
			if (i == 0)
				datax.opcode = token;
			if (strcmp(datax.opcode, "push") != 0)
				break;
			if (i == 1)
				verify_number(token);
			token = strtok(NULL, " \n");
		}
		if (strcmp(datax.opcode, "push") == 0 && i == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", datax.line_num);
			free_stack(datax.top);
			exit(EXIT_FAILURE);
		}
		exec();
	}
	free_stack(datax.top);
	exit(EXIT_SUCCESS);
}
