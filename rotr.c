#include "monty.h"

/**
 * rotr - The opcode rotr rotates the stack to the bottom.
 * @top: A pointer to top of stack.
 */

void rotr(stack_t **top)
{
	stack_t *last = *top;

	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}

	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = *top;
	*top = last->next;
	last->next = NULL;
}
