#include "monty.h"

/**
 * execute_script - execute monty script
 * @filename: file name
 *
 * Return: always 1
 */
int execute_script(char *filename)
{
	char *input_str = NULL, *line = NULL, **tokens = NULL;
	const int INITIAL_LINE_SIZE = 1024;
	int index = 0, l_index = 0, line_number = 1;

	line = malloc(INITIAL_LINE_SIZE);
	if (line == NULL)
	{
		free_stack();
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	input_str = read_textfile(filename, line);
	while (input_str[index] != '\0')
	{
		l_index = 0;
		while (input_str[index] != '\n' && index < INITIAL_LINE_SIZE)
		{
			line[l_index] = input_str[index];
			l_index++;
			index++;
		}
		line[l_index] = '\0';
		tokens = tokenize(line, " \t", _strlen(line));
		if (tokens && _tokenlen(tokens) >= 1)
			execute_arg(line_number, tokens, line, input_str);
		index++;
		line_number++;
		free_memory_tokens(tokens);
	}
	free(input_str);
	free(line);
	return (1);
}

/**
 * execute_arg - execute one argument commands
 * @line_number: command line number
 * @tokens: line tokens
 * @line: current line
 * @input_str: total script string
 *
 * Return: nothing
 */
void execute_arg(int line_number, char **tokens, char *line, char *input_str)
{
	if (_strcmp(tokens[0], "pall") == 0)
		pall();
	else if (_strcmp(tokens[0], "push") == 0)
		if (_tokenlen(tokens) == 1)
			push(NULL, line_number, tokens, line, input_str);
		else
			push(tokens[1], line_number, tokens, line, input_str);
	else if (_strcmp(tokens[0], "pint") == 0)
		pint(line_number, tokens, line, input_str);
	else if (_strcmp(tokens[0], "pop") == 0)
		pop(line_number, tokens, line, input_str);
	else if (_strcmp(tokens[0], "swap") == 0)
		swap(line_number, tokens, line, input_str);
	else if (_strcmp(tokens[0], "add") == 0)
		add(line_number, tokens, line, input_str);
	else if (_strcmp(tokens[0], "nop") == 0)
		;
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tokens[0]);
		free_stack();
		free_memory_tokens(tokens);
		free(line);
		free(input_str);
		exit(EXIT_FAILURE);
	}
}
