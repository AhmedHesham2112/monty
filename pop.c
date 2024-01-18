#include "monty.h"

/**
 * pop - removes a node from the stack.
 * @stack: pointing to top node of the stack.
 * @line_no: the line no. of of the opcode.
 */
void pop(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_no);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
