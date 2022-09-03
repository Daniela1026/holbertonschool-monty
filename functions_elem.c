#include "monty.h"

int value;
/**
*
*
*
*/
stack_t *newnode(int n)
{
        stack_t *new = NULL;

        new = malloc(sizeof(stack_t));
        if (new == NULL)
        {
                dprintf(STDERR_FILENO, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }
        new->n = n;
        new->next = NULL;
        new->prev = NULL;

        return (new);
}


/**
*
*
*
*/
void _push(stack_t **stack, unsigned int line_number)
{

	stack_t *new = NULL;
	(void)line_number;

	new = newnode(value);

	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
*
*
*
*/
void _pall(stack_t **stack, unsigned int n)
{
	stack_t *current = NULL;
	(void)n;

	current = *stack;

	while (current != NULL)
	{
		dprintf(STDOUT_FILENO, "%d\n", current->n);
		current = current->next;
	}
}

/**
*
*
*
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

/**
*
*
*
*/
int _isdigit(char *c)
{
	char *aux = c;

	if (c == NULL)
		return (0);
	if (*aux == '-')
		aux++;

	for (; *aux != '\0'; aux++)
	{
		if ((*aux < '0' || *aux > '9'))
		{
			return (0);
		}
	}
	return (1);
}

/**
 * _pint - prints the value at the top of the stack.
 * @stack: Stack list
 * @line_number: Number of the line
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	else
		dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}
