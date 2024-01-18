#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_no: Interger representing the line number of of the opcode.
 */
void swap(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_no, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
