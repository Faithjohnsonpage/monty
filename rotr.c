#include "monty.h"

/**
 * rotr - The opcode rotr rotates the stack to the bottom.
 * @top: A pointer to top of stack.
 */

void rotr(stack_t **top)
{
	stack_t *first = NULL, *second = NULL, *last = NULL;

	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}

	first = *top;
	second = *top;

	while (second->next != NULL)
	{
		last = second;
		second = second->next;
	}

	last->next = NULL;
	second->next = first;
	*top = second;
}
