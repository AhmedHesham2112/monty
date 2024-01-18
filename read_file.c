#include "monty.h"

/**
 * read_file - reads the file
 * @f: pointer to the file
 * Return: void
 */

void read_file(FILE *f)
{
	int line_no = 1, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_no = 1; getline(&buffer, &len, f) != -1; line_no++)
	{
		format = tokenize_line(buffer, line_no, format);
	}
	free(buffer);
}
