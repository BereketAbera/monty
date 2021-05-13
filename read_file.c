#include "monty.h"

/**
 * read_textfile - react contents of a file
 * @filename: a file name to read
 * @line: current line string
 *
 * Return: file content
 */
char *read_textfile(const char *filename, char *line)
{
	int fd, read_value;
	char *buf;
	char *total_buf = NULL;
	const int INITIAL_BUF_SIZE = 1024;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		free(line);
		exit(EXIT_FAILURE);
	}
	buf = malloc(INITIAL_BUF_SIZE + 1);
	if (buf == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free(line);
		exit(EXIT_FAILURE);
	}

	read_value = read(fd, buf, INITIAL_BUF_SIZE);

	buf[INITIAL_BUF_SIZE + 1] = '\0';
	while (read_value != 0)
	{
		total_buf = _strconcat(total_buf, buf);
		read_value = read(fd, buf, INITIAL_BUF_SIZE);
	}

	close(fd);
	free(buf);
	return (total_buf);
}
