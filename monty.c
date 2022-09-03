#include "monty.h"

glob_t global = {NULL, NULL};

/**
* main - main
* @argc: Character int
* @argv: Character char
* Return:  Always 0
*/


int main(int argc, char *argv[])
{
	if (argc == 2)
		_command(argv[1]);
	else
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
