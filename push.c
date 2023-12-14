#include "monty.h"

stack_t *top = NULL;

/**
 * push_to_stack - Pushes an integer onto the stack.
 * @argument_to_push: The value to be pushed onto the stack.
 *
 * This function creates a new node with the given integer value and adds
 * it to the top of the stack. If the stack is empty, it initializes the
 * top of the stack with the new node.
 */

void push_to_stack(char *argument_to_push)
{
	stack_t *newnode = NULL;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newnode->n = atoi(argument_to_push);
	newnode->prev = NULL;
	newnode->next = NULL;

	if (top == NULL)
	{
		top = newnode;
	}
	else
	{
		newnode->next = top;
		top->prev = newnode;
		top = newnode;
	}
}
