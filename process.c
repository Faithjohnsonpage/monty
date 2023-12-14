#include "monty.h"

void process_file(const char *path);

/**
 * is_valid_instruction - Placeholder function to check the validity of a
 *                       Monty instruction.
 * @instruction: String representing the Monty instruction to be validated.
 *
 * Return: Returns 1 as a placeholder; should be replaced with actual
 *         validation logic.
 */

int is_valid_instruction(const char *instruction)
{
	unsigned int i;
	const char *opcode[] = {"push", "pall", "pint", "pop", "swap", "add", "nop"};

	/* Loop through the array to check if the given instruction is valid */
	for (i = 0; i < sizeof(opcode) / sizeof(opcode[0]); i++)
	{
		if (strcmp(instruction, opcode[i]) == 0)
		{
			return (1);
		}
	}

	return (0);
}

/**
 * process_file - Processes a Monty bytecode file, extracting and validating
 *                instructions.
 * @path: String representing the file path of the Monty bytecode file
 *        to be processed.
 */

void process_file(const char *path)
{
	FILE *file = NULL;
	char *line = NULL, *opcode = NULL, *argument = NULL;
	size_t len = 0;
	ssize_t line_read;
	int line_num = 0;
	instruction_t instruction;

	file = fopen(path, "r");
	if (file == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while ((line_read = getline(&line, &len, file)) != -1)
	{
		line_num++;

		if (line_read > 0 && line[line_read - 1] == '\n')
			line[line_read - 1] = '\0';

		/* Ignore blank lines (lines made of spaces only or entirely empty) */
		if (strspn(line, " \t\n") == strlen(line))
			continue;

		opcode = strtok(line, " \t\n$");
		if (opcode != NULL)
		{
			if (strcmp(opcode, "push") == 0)
			{
				argument = strtok(NULL, " \t$\n");

				if (argument == NULL || !(*argument >= '0' && *argument <= '9'))
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_num);
					free(line);
					fclose(file);
					exit(EXIT_FAILURE);
				}
			}

			/* Check if the instruction is valid */
			if (!is_valid_instruction(opcode))
			{
			fprintf(stderr, "Error: L%d: unknown instruction %s\n", line_num, opcode);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE);
			}
		}

		/* Process the valid instruction here */
		instruction.opcode = opcode;

		if (strcmp(instruction.opcode, "push") == 0)
		{
			push_to_stack(argument);
		}
		else if (strcmp(instruction.opcode, "pall") == 0)
		{
			display_stack();
		}

	}

	free(line);
	fclose(file);
}
