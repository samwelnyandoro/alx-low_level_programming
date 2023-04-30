#include "lists.h"

/**
 * get_nodeint_at_index - functions that returns the nth node of a listint_t
 * linked list else return NULL
 * @head: pointer to a head of a list.
 * @index: the index of the node, starting at 0
 *
 * Return: Always 0
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *node;

	if (!head)
		return (NULL);

	node = head;
	while (i < index)
	{
		if (!node)
			return (NULL);
		node = node->next;
		i++;
	}
	return (node);
}
