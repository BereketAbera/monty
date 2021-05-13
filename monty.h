#ifndef DECLARE_VARIABLE
#define DECLARE_VARIABLE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *stack;

char *read_textfile(const char *filename, char *line);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strlen(char *str);
char *_strconcat(char *first_string, char *second_string);
char *_trim(char *input);
char *_strdup(char *str);
char **tokenize(char *input, char *separator, int length);
int _tokenlen(char **tokens);
int execute_script(char *filename);
void *push(char *value, int ln, char **tokens, char *line, char *input_str);
void pall(void);
int _pow(int base, int exp);
int getNumericValue(char *token, int len);
int checkNumber(char *token);
int _strcmp(char *s1, char *s2);
void pint(int line_number, char **tokens, char *line, char *input_str);
void pop(int line_number, char **tokens, char *line, char *input_str);
void free_stack(void);
void free_memory_tokens(char **tokens);
void swap(int line_number, char **tokens, char *line, char *input_str);
void add(int line_number, char **tokens, char *line, char *input_str);
void execute_arg(int line_number, char **tokens, char *line, char *input_str);
void free_all(char **tokens, char *line, char *input_str);
void print_err(int ln, char **tokens, char *line, char *input_str);

#endif
