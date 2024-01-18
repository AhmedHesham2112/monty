#include "monty.h"

/**
 * open_file - open the file
 * @file_name: the file name
 * Return: void
 */

void open_file(char *file_name)
{
	FILE *f = fopen(file_name, "r");

	if (file_name == NULL || f == NULL)
		err(2, file_name);

	read_file(f);
	fclose(f);
}
