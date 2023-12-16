#include "monty.h"

/**
 * main - Entry point of the program.
 * @ac: Number of command-line arguments.
 * @av: Array of command-line argument strings.
 *
 * Return: Returns 0 on successful execution.
 */

int main(int ac, char *av[])
{
	stack_t *top = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	process_file(av[1], &top);

	return (0);
}
