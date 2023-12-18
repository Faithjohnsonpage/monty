#include "monty.h"

void rotl(stack_t **top)
{
	stack_t *first = NULL, *second = NULL, *last = NULL;

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
