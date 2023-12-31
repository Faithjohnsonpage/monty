#include "monty.h"

/**
 * pchar - Prints the character value at the top of the stack.
 * @top: A pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file.
 * @file: A pointer to the FILE structure representing the Monty file.
 * @line: A pointer to the dynamically allocated buffer for reading lines.
 *
 * Description:
 * This function prints the character value at the top of the stack. It checks
 * if the stack is empty or if the value is out of the ASCII range (0 to 127).
 * If successful, it prints the character to the standard output.
 *
 */

void pchar(stack_t **top, int line_number, FILE *file, char *line)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(line);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	if ((*top)->n < 0 || (*top)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(line);
		fclose(file);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*top)->n);
}
