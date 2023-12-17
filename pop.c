#include "monty.h"

/**
 * pop - Function removes the top element of the stack.
 * @top: A pointer to the top of stack.
 * @line_number: the line where we have the pop command.
 */

void pop(stack_t **top, int line_number)
{
	stack_t *temp = *top;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	*top = (*top)->next;
	free(temp);
}
