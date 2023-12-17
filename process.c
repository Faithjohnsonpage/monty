#include "monty.h"

void process_file(const char *filename, stack_t **top);

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
	const char *opcode[] = {
		"push",
		"pall",
		"pint",
		"pop",
		"swap",
		"add",
		"nop",
		"sub",
		"div",
		"mul",
		"mod"
	};

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
 * @filename: String representing the file path of the Monty bytecode file
 *        to be processed.
 * @top: A pointer to the top of the stack.
 */

void process_file(const char *filename, stack_t **top)
{
	FILE *file = NULL;
	char *line = NULL, *opcode = NULL, *argument = NULL;
	size_t len = 0;
	ssize_t line_read;
	int line_num = 0;
	instruction_t instruction;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
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

		if (line[0] == '#')
			continue; /* Ignore comments */

		opcode = strtok(line, " \t\n$");
		if (opcode != NULL)
		{
			if (strcmp(opcode, "push") == 0)
			{
				argument = strtok(NULL, " \t$\n");
			}

			/* Check if the instruction is valid */
			if (!is_valid_instruction(opcode))
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
				free(line);
				fclose(file);
				exit(EXIT_FAILURE);
			}
		}

		/* Process the valid instruction here */
		instruction.opcode = opcode;

		if (strcmp(instruction.opcode, "push") == 0)
		{
			push_to_stack(top, line_num, argument);
		}
		else if (strcmp(instruction.opcode, "pall") == 0)
		{
			display_stack(top);
		}
		else if (strcmp(instruction.opcode, "pint") == 0)
		{
			pint(top, line_num);
		}
		else if (strcmp(instruction.opcode, "pop") == 0)
		{
			pop(top, line_num);
		}
		else if (strcmp(instruction.opcode, "swap") == 0)
		{
			swap(top, line_num);
		}
		else if (strcmp(instruction.opcode, "add") == 0)
		{
			add(top, line_num);
		}
		else if (strcmp(instruction.opcode, "nop") == 0)
		{
			continue;
		}
		else if (strcmp(instruction.opcode, "sub") == 0)
		{
			sub(top, line_num);
		}
		else if (strcmp(instruction.opcode, "div") == 0)
		{
			divide_stack(top, line_num);
		}
		else if (strcmp(instruction.opcode, "mul") == 0)
		{
			mul(top, line_num);
		}
		else if (strcmp(instruction.opcode, "mod") == 0)
		{
			mod(top, line_num);
		}

	}

	free(line);
	fclose(file);
}
