#include "monty.h"

/**
 * add - adds the top two nodes of the stack.
 * @stack: the top node of the stack.
 * @line_no: the line no. of the opcode.
 */
void add(stack_t **stack, unsigned int line_no)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_no, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
