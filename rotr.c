#include "monty.h"

/**
 * rotr - The opcode rotr rotates the stack to the bottom.
 * @top: A pointer to top of stack.
 */

void rotr(stack_t **top)
{
	stack_t *first = NULL, *last = NULL;

	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}

	first = *top;
	last = *top;

	while (last->next != NULL)
	{
		last = last->next;
	}

	*top = last;
	first->next = NULL;
}
