#include "monty.h"

/**
 * execute_instructions - executes Monty bytecode instructions
 * @filename: path to the bytecode file
 * Return: 0 on success, 1 on failure
 */
int execute_instructions(char *filename)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t read;
	unsigned int line_count = 1;
	instruct_func func_ptr;
	int fclose_check;

	var_global.file = fopen(filename, "r");
	if (var_global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return 1;
	}

	while ((read = getline(&var_global.buffer, &bufsize, var_global.file)) != -1)
	{
		line = parse_line(var_global.buffer, &stack, line_count);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		func_ptr = get_op_func(line);
		if (func_ptr == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
			fclose(var_global.file);
			free(var_global.buffer);
			free_dlistint(stack);
			return 1;
		}
		func_ptr(&stack, line_count);
		line_count++;
	}

	fclose_check = fclose(var_global.file);
	free(var_global.buffer);
	free_dlistint(stack);

	if (fclose_check == EOF)
	{
		fprintf(stderr, "Error: Can't close file %s\n", filename);
		return 1;
	}

	return 0;
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return 1;
	}

	return execute_instructions(argv[1]);
}

