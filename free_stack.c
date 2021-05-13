#include "monty.h"

/**
 * free_stack - free stack
 *
 * Return: nothing
 */
void free_stack(void)
{
	stack_t *temp_stack;

	while (stack != NULL)
	{
		temp_stack = stack;
		stack = stack->next;
		free(temp_stack);
	}

	free(stack);
}

/**
 * free_memory_tokens - free the memory assigned for tokens
 * @tokens: the given tokens
 *
 * Return: Nothing
 **/
void free_memory_tokens(char **tokens)
{
	char **tmp = tokens;

	if (tokens)
	{
		while (*tokens)
		{
			free(*tokens++);
		}
		free(tmp);
	}
}

/**
 * free_all - free all variables
 * @tokens: line tokens
 * @line: current line
 * @input_str: total script string
 *
 * Return: nothing
 */
void free_all(char **tokens, char *line, char *input_str)
{
	free_memory_tokens(tokens);
	free(line);
	free(input_str);
	free_stack();
}
