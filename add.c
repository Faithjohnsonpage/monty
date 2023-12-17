#include "monty.h"

/**
 * add - Implementing the opcode add that adds the top two elements of stack
 * @top: - A pointer to the top of stack.
 * @line_number: - the line number of the file considered.
 */

void add(stack_t **top, int line_number)
{
	stack_t *temp = NULL, *current = NULL;
	int sum = 0;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *top;
	current = (*top)->next;
	sum = temp->n + current->n;
	current->n = sum;
	*top = (*top)->next;
	free(temp);
}
