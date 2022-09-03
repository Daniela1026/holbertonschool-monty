#include "monty.h"

/**
*
*
*
*/

void _command(char *argv)
{
	size_t bufsize = 0;
	stack_t *stack = NULL;
	int n = 0;
	int result = 0;
	char *arg = NULL;
	char *item = NULL;

	global.fd = fopen(argv, "r");
	if (global.fd)
	{ 
		while (getline(&global.line, &bufsize, global.fd) != -1)
		{
			n++;
			arg = strtok(global.line, " \n\t\r");
			if (arg == NULL)
			{
				free(arg);
				continue;
			}
			else if (*arg == '#')
				continue;
			item = strtok(NULL, " \n\t\r");
			result = get_(&stack, arg, item, n);
			if (result == 1)
				p_error(global.fd, global.line, stack, n);
			else if (result == 2)
				i_error(global.fd, global.line, stack, arg, n);
		}
		free(global.line);
		free_dlistint(stack);
		fclose(global.fd);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}

