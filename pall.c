#include "monty.h"

/**
 * display_stack - Prints all elements in the stack.
 */

void display_stack(void)
{
	stack_t *temp = top;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
