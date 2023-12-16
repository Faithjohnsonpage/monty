#include "monty.h"

/**
 * free_stack - Frees all nodes in a stack.
 * @top: A pointer to the top of the stack.
 *
 * Description:
 * This function traverses a linked list starting from the provided
 * top pointer and frees each node. After the operation, the top pointer
 * is set to NULL to ensure it no longer points to the deallocated memory.
 */

void free_stack(stack_t *top)
{
	stack_t *temp = top;

	while (top != NULL)
	{
		temp = top;
		top = top->next;
		free(temp);
	}

}
