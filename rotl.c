#include "monty.h"

/**
 * rotl - The opcode rotl rotates the stack to the top.
 * @top: A pointer to the top of stack.
 */

void rotl(stack_t **top)
{
	stack_t *first = NULL, *second = NULL, *last = NULL;

	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}

	first = *top;
	second = (*top)->next;
	last = *top;

	while (last->next != NULL)
	{
		last = last->next;
	}

	/* Update pointers for left rotation */
	*top = second;
	last->next = first;
	first->next = NULL;
}
