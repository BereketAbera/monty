#include "monty.h"

/**
 * _trim - function that trims empty spaces and new lines
 * @input: the given string
 *
 * Return: the cleaned string
 **/
char *_trim(char *input)
{
	int i, j;

	i = 0;
	j = 0;
	while (input[i] == ' ' || input[i] == '\t' || input[i] == '\n')
	{
		i++;
	}
	while (input[i + j] != '\0')
	{
		input[j] = input[i + j];
		j++;
	}
	input[j] = '\0';

	i = 0;
	j = -1;
	while (input[i] != '\0')
	{
		if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n')
		{
			j = i;
		}
		i++;
	}
	input[j + 1] = '\0';
	return (input);
}

/**
 * tokenize - function that splits a string
 * @input: the given string
 * @separator: the delimiter
 * @length: the lenght of a string
 *
 * Return: the tokens on success or NULL otherwise
 **/
char **tokenize(char *input, char *separator, int length)
{
	char *token = NULL;
	char **tokens = NULL;
	char *tmp = NULL;
	int i = 0;

	if (input == NULL)
		return (NULL);
	input = _trim(input);
	if (input[0] != '\0')
	{
		tokens = malloc(sizeof(char *) * (length + 1));
		if (tokens == NULL)
		{
			fprintf(stderr, "Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		tmp = _strdup(input);
		token = strtok(tmp, separator);
		while (token)
		{
			tokens[i] = _strdup(token);
			token = strtok(NULL, separator);
			i++;
		}
		tokens[i] = '\0';
		if (token)
			free(token);
		if (tmp)
			free(tmp);
	}
	return (tokens);
}

/**
 * _tokenlen - get token length
 * @tokens: tokens
 *
 * Return: number of tokens
 */
int _tokenlen(char **tokens)
{
	int len = 0;

	while (tokens != NULL && tokens[len] != NULL)
		len++;

	return (len);
}
