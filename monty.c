#include "monty.h"

glob_t global = {NULL, NULL};
/**
*
* 
*
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
