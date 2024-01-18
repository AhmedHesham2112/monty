#include "monty.h"

/**
 * err - handles errors.
 * @err_code: The code of the error
 * Return: Void.
 */
void err(int err_code, ...)
{
	va_list ag;
	char *op;
	int num;

	va_start(ag, err_code);
	switch (err_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - handles errors.
 * @err_code: The code of the error
 * Return: Void
 */
void more_err(int err_code, ...)
{
	va_list ag;
	char *op;
	int num;

	va_start(ag, err_code);
	switch (err_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num, op);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
