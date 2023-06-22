#include "monty.h"

/**
 * _swap - swap top of stack with second top of stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int temp;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = top->n;
	top->n = top->next->n;
	top->next->n = temp;
}

/**
 * _add - add the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int sum;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = top->n + top->next->n;
	_pop(stack, line_number);
	top->n = sum;
}

/**
 * _nop - do nothing
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */
void _nop(__attribute__ ((unused)) stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
	/* Do nothing */
}

/**
 * _pchar - print the ASCII value of the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int val;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	val = top->n;
	if (val < 0 || val > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(val);
	putchar('\n');
}

/**
 * _isalpha - checks if an integer is an alphabetic character
 * @c: integer
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

