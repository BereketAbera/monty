#include "holberton.h"


/**
 * main - entry point to the whole application
 * @argc: argument count
 * @argv: argument values
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	execute_script(argv[1]);
	free_stack();
}
