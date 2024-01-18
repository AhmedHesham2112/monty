#include "monty.h"

/**
 * tokenize_line - tokenize the line
 * @buffer: line from the file
 * @line_no: line number
 * @format:  storage format. If 0 Nodes -> a stack.
 * if 1 nodes -> a queue.
 * Return: Returns 0 if stack. 1 if queue.
 */

int tokenize_line(char *buffer, int line_no, int format)
{
	char *code, *val;
	const char *token = "\n ";

	if (buffer == NULL)
		err(4);

	code = strtok(buffer, token);
	if (code == NULL)
		return (format);
	val = strtok(NULL, token);

	if (strcmp(code, "stack") == 0)
		return (0);
	if (strcmp(code, "queue") == 0)
		return (1);

	find_func(code, val, line_no, format);
	return (format);
}
