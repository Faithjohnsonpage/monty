#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack.
 * @top: A pointer to the top of the stack.
 */

void pstr(stack_t **top)
{
	stack_t *temp = *top;

	if (*top == NULL)
	{
		printf("\n");
	}
	else
	{

		while (temp != NULL && temp->n != 0)
		{
			if (temp->n < 0 || temp->n > 127)
			{
				break;
			}

			printf("%c", temp->n);
			temp = temp->next;
		}

		printf("\n");
	}

}
