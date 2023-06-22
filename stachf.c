#include "monty.h"

/**
 * _push - push int to a stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int value = var_global.push_arg;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * _pall - print all function
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * _pint - print int at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", top->n);
}

/**
 * _pop - remove the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = top->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);
}

/**
 * free_dlistint - free a stack
 * @head: pointer to the head of the stack
 */
void free_dlistint(stack_t *head)
{
	stack_t *current = head;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

