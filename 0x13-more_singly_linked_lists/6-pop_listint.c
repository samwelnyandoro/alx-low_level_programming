#include "lists.h"

/**
 * pop_listint - function that deleted the head node of a listint_t
 * linked list and returns the head node's data(n)
 * @head: pointer of a pointer to a listint_t
 *
 * Return: Always 0
 */
int pop_listint(listint_t **head)
{
	int value;
	listint_t *new_head;

	if (!(*head) || !head)
		return (0);

	new_head = (*head)->next;
	value = (*head)->n;
	free(*head);
	*head = new_head;

	return (value);
}
