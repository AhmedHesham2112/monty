#include "monty.h"

/**
 * find_func - find the appropriate function for the opcode
 * @code: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes -> stack if 1 nodes -> queue.
 * @ln: line no.
 * Return: void
 */

void find_func(char *code, char *val, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}};

	if (code[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(code, func_list[i].opcode) == 0)
		{
			call_func(func_list[i].f, code, val, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, code);
}

/**
 * call_func - Calls the function.
 * @func: the function to be called.
 * @op: string of the opcode.
 * @val: string of the numeric value.
 * @ln: the line no.
 * @format: Format specifier. If 0 Nodes -> stack if 1 nodes -> queue.
 * Return: void
 */

void call_func(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
