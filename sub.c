#include "monty.h"

/**
 * sub - subtracts the top element of the stack
 * 		 from the second top element of the stack.
 * @top: A pointer to the top of stack.
 * @line_number: The line number of the file treated.
 */

void sub(stack_t **top, int line_number)
{
	stack_t *temp = NULL, *current = NULL;
	int sub = 0;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	}

	temp = *top;
	current = (*top)->next;
	sub = current->n - temp->n;
	current->n = sub;
	*top = (*top)->next;
	free(temp);
}
