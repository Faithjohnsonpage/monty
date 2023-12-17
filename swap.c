#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @top: A pointer to the top of the stack.
 * @line_number: The line number of the Monty bytecode file.
 */

void swap(stack_t **top, int line_number)
{
	stack_t *temp = NULL, *current = NULL;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *top;
	current = (*top)->next;

	temp->prev = current->prev;
	temp->next = current->next;
	current->next = temp;
	current->prev = NULL;

	if (temp->prev != NULL)
		temp->prev = current;

	if (temp->next != NULL)
		temp->next->prev = temp;

	*top = current;
}
