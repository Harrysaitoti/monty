#include "monty.h"

/**
 * _push - push int to a stack
 * @stack: pointer to the stack
 */
void _push(stack_t **stack)
{
    int value = 0;  /* Replace 0 with the value to be pushed */

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
 */
void _pall(stack_t **stack)
{
    stack_t *current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * _pint - print int at the top of the stack
 * @stack: pointer to the stack
 */
void _pint(stack_t **stack)
{
    stack_t *top = *stack;

    if (top == NULL)
    {
        fprintf(stderr, "Error: can't pint, stack empty\n");
        exit(EXIT_FAILURE);
    }

    printf("%d\n", top->n);
}

/**
 * _pop - remove the top element of the stack
 * @stack: pointer to the stack
 */
void _pop(stack_t **stack)
{
    stack_t *top = *stack;

    if (top == NULL)
    {
        fprintf(stderr, "Error: can't pop an empty stack\n");
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

/**
 * _swap - swap top of stack with second top of stack
 * @stack: pointer to the stack
 */
void _swap(stack_t **stack)
{
    stack_t *top = *stack;
    int temp;

    if (top == NULL || top->next == NULL)
    {
        fprintf(stderr, "Error: can't swap, stack too short\n");
        exit(EXIT_FAILURE);
    }

    temp = top->n;
    top->n = top->next->n;
    top->next->n = temp;
}

/**
 * _add - add the top two elements of the stack
 * @stack: pointer to the stack
 */
void _add(stack_t **stack)
{
    stack_t *top = *stack;
    int sum;

    if (top == NULL || top->next == NULL)
    {
        fprintf(stderr, "Error: can't add, stack too short\n");
        exit(EXIT_FAILURE);
    }

    sum = top->n + top->next->n;
    _pop(stack);
    top->n = sum;
}

/**
 * _nop - do nothing
 * @stack: pointer to the stack
 */
void _nop(stack_t **stack)
{
    /* Do nothing */
}

/**
 * _pchar - print the ASCII value of the
