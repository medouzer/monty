#include "monty.h"

/**
 * rm_spaces - is the function that remove spaces
 * @str: is the string to remove spaces
 * Return: new string
 */

char *rm_spaces(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			str++;
		else
			break;
	}
	return (str);
}

/**
 * openfile - is the function to open file
 * @filename: file name
 * Return: FILE
 */

FILE *openfile(char *filename)
{
	FILE *mfile;

	mfile = fopen(filename, "r");
	if (!mfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (mfile);
}

/**
 * verify_number - this function verify is number
 * @token: is a string
 * Return: none
 */

void verify_number(char *token)
{
	int i = 0;

	if (atoi(token) < 0)
		i++;
	if ((isdigit(token[i]) && strlen(token) == num_len(atoi(token))) ||
		(token[0] == '-' && isdigit(token[1])))
		datax.push_value = atoi(token);
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", datax.line_num);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
}

/**
 * num_len - count the len of the number
 * @num: number
 * Return: the number lentgh
 */

size_t num_len(int num)
{
	int len = 0;

	if (!num)
		return (1);
	if (num <= 0)
		len++;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}
