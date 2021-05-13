#include "monty.h"

/**
 * add - add the top two elements
 * @line_number: command line number
 * @tokens: line tokens
 * @line: current line string
 * @input_str: total script string
 *
 * Return: nothing
 */
void add(int line_number, char **tokens, char *line, char *input_str)
{
	stack_t *temp;

	if (stack == NULL || stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all(tokens, line, input_str);
		exit(EXIT_FAILURE);
	}

	stack->n = stack->n + stack->next->n;
	temp = stack->next;
	stack->next = stack->next->next;
	stack->next->prev = stack;
	free(temp);
}
