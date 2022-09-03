#include "monty.h"

/**
* free_dlistint - Free a list
* @stack: Parameter
*/
void free_dlistint(stack_t *stack)
{
	stack_t *current = NULL;

	current = stack;

	if (current != NULL)
	{
		free_dlistint(current->next);
		free(current);
	}
}
