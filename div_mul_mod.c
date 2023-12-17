#include "monty.h"

/**
 * divide_stack - divides the second top element of the stack
 * by the top element of the stack.
 * @top: A pointer to the top of stack.
 * @line_number: The line number of the file treated.
 */

void divide_stack(stack_t **top, int line_number)
{
	stack_t *temp = NULL, *current = NULL;
	int div;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *top;
	current = (*top)->next;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	div = current->n / temp->n;
	current->n = div;
	*top = (*top)->next;
	free(temp);
}


/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack.
 *
 * @top: A pointer to the top of stack.
 * @line_number: The line number of the file treated.
 */

void mul(stack_t **top, int line_number)
{
	stack_t *temp = NULL, *current = NULL;
	int mul;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *top;
	current = (*top)->next;
	mul = current->n * temp->n;
	current->n = mul;
	*top = (*top)->next;
	free(temp);
}


/**
 * mod - The opcode mod computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 *
 * @top: A pointer to the top of stack.
 * @line_number: The line number of the file treated.
 */

void mod(stack_t **top, int line_number)
{
	stack_t *temp = NULL, *current = NULL;
	int mod;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *top;
	current = (*top)->next;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	mod = current->n % temp->n;
	current->n = mod;
	*top = (*top)->next;
	free(temp);
}
