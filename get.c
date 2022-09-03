#include "monty.h"

int get_(stack_t **stack, char *arg, char *item, int n)
{
	int i = 0;

	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	while (op[i].opcode)
	{
		if (!strcmp(arg, op[i].opcode))
		{
			if (!strcmp(arg, "push"))
			{
				if (_isdigit(item) == 1)
					value = atoi(item);
				else
					return (1);
			}
			op[i].f(stack, (unsigned int)n);
			break;
		}
		i++;
	}
	if (!op[i].opcode)
		return (2);

	return (0);
}
