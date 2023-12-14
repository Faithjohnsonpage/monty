#include "monty.h"

/**
 * is_not_file - Checks if the specified path does not refer to a regular file.
 * @path: String representing the file path to be examined.
 *
 * Return: Returns 1 if the path does not correspond to a regular file;
 *         otherwise, returns 0.
 */

int is_not_file(const char *path)
{
	struct stat path_stat;

	if (stat(path, &path_stat) == 0)
	{
		if (!S_ISREG(path_stat.st_mode))
			return (1);
		else
			return (0);
	}
	else
	{
		perror("stat");
		exit(EXIT_FAILURE);
	}
}

/**
 * cannot_open_file - Determines whether the file specified by the given path
 * cannot be opened for reading.
 * @path: String representing the file path to be checked.
 *
 * Return: Returns 1 if the file cannot be opened; otherwise, returns 0.
 */

int cannot_open_file(const char *path)
{
	if (access(path, R_OK) == -1)
		return (1);
	else
		return (0);
}

/**
 * main - Entry point of the program.
 * @ac: Number of command-line arguments.
 * @av: Array of command-line argument strings.
 *
 * Return: Returns 0 on successful execution.
 */

int main(int ac, char *av[])
{
	if (ac < 2 || is_not_file(av[1]))
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (cannot_open_file(av[1]))
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	process_file(av[1]);

	return (0);
}
