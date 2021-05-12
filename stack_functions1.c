#include "holberton.h"

stack_t *stack = NULL;

/**
 * push - add not to the top of the stack
 * @value: value of the new node
 * @ln: script line number
 * @tokens: line tokens
 * @line: current line string
 * @input_str: total script string
 *
 * Return: nothing
 */
void *push(char *value, int ln, char **tokens, char *line, char *input_str)
{
	stack_t *new_node;
	int n;

	if (checkNumber(value) == 0)
	{
		printf("L%d: usage: push integer\n", ln);
		free_all(tokens, line, input_str);
		exit(EXIT_FAILURE);
	}
	n = getNumericValue(value, _strlen(value));
	if (stack == NULL)
	{
		stack = malloc(sizeof(stack_t));
		if (stack == NULL)
		{
			free_all(tokens, line, input_str);
			exit(EXIT_FAILURE);
		}
		stack->n = n;
		return (stack);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free_all(tokens, line, input_str);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = stack;
	if (stack != NULL)
		stack->prev = new_node;
	stack = new_node;

	return (new_node);
}

/**
 * pall - prints out content of the stack
 *
 * Return: nothing
 */
void pall(void)
{
	stack_t *temp_node = stack;

	while (temp_node != NULL)
	{
		printf("%d\n", temp_node->n);
		temp_node = temp_node->next;
	}
}

/**
 * pint - prints the value of the top of the stack
 * @ln: script line number
 * @tokens: line tokens
 * @line: current script line string
 * @input_str: total script string
 *
 * Return: nothing
 */
void pint(int ln, char **tokens, char *line, char *input_str)
{
	stack_t *temp_node = stack;

	if (temp_node != NULL)
		printf("%d\n", temp_node->n);
	else
	{
		printf("L%d: can't pint, stack empty\n", ln);
		free_all(tokens, line, input_str);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - remove the top the stack
 * @ln: script line number
 * @tokens: line tokens
 * @line: current line string
 * @input_str: total script string
 *
 * Return: nothing
 */
void pop(int ln, char **tokens, char *line, char *input_str)
{
	if (stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", ln);
		free_all(tokens, line, input_str);
		exit(EXIT_FAILURE);
	}

	if (stack->prev)
	{
		free(stack->prev);
		stack->prev = NULL;
	}
	stack = stack->next;
}

/**
 * swap - swap the top two elements
 * @ln: script line number
 * @tokens: linke tokens
 * @line: current line string
 * @input_str: total script string
 *
 * Return: nothing
 */
void swap(int ln, char **tokens, char *line, char *input_str)
{
	stack_t *temp;

	if (stack == NULL || stack->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", ln);
		free_all(tokens, line, input_str);
		exit(EXIT_FAILURE);
	}

	temp = stack;
	stack = stack->next;
	temp->next = stack->next;
	stack->next = temp;
	temp->prev = stack;
	stack->prev = NULL;
}
