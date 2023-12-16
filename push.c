#include "monty.h"

/**
 * push_to_stack - Pushes an integer onto the stack.
 * @top: A pointer to the top of the stack.
 * @line_number: The line number of the Monty bytecode file.
 * @argument: The integer argument to be pushed onto the stack.
 *
 * Description:
 * This function adds a new node to the top of the stack with the provided
 * integer argument. If the stack cannot be created, it prints an error
 * message with the line number and exits the program.
 */

void push_to_stack(stack_t **top, int line_number, char *argument)
{
	stack_t *newnode = NULL;
	char *checked_argument;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	checked_argument = is_arg_integer(line_number, argument);

	newnode->n = atoi(checked_argument);
	newnode->prev = NULL;
	newnode->next = NULL;

	if (*top == NULL)
	{
		*top = newnode;
	}
	else
	{
		newnode->next = *top;
		(*top)->prev = newnode;
		*top = newnode;
	}
}

/**
 * is_arg_integer - Checks if an argument is a valid integer.
 * @line_number: The line number of the Monty bytecode file.
 * @argument: The argument to be checked.
 *
 * Description:
 * This function validates whether the given argument is a valid integer.
 * It checks for proper integer format and handles error cases, printing
 * an error message with the line number and exiting the program if needed.
 *
 * Return: argument is returned if valid, else prints error message.
 */

char *is_arg_integer(int line_number, char *argument)
{
	int i;

	if (argument == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; argument[i] != '\0'; i++)
	{
		if (i == 0 && (argument[i] == '-' || argument[i] == '+'))
		{
			continue;
		}

		if (!isdigit(argument[i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (argument);
}
