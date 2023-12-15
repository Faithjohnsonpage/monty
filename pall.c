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

/*
 * pint -  prints the value at the top of the stack
 * @line_number: the line where we have the opcode pint
 */

void pint(int line_number)
{
	if (top == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d", top->n);
	}
}
