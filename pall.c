#include "monty.h"

/**
 * pall - prints all the nodes in the stack.
 * @stack: the top node of the stack.
 * @line_no: line no. of  the opcode.
 */
void pall(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp;

	(void) line_no;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
