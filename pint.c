#include "monty.h"

/**
 * pint - prints the top node of the stack.
 * @stack: the top node of the stack.
 * @line_no: the line no. of of the opcode.
 */

void pint(stack_t **stack, unsigned int line_no)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_no);
	printf("%d\n", (*stack)->n);
}
