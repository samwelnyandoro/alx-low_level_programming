#include "lists.h"

/**
 * free_listint - function that frees a listint_t list
 * @head: pointer to a list.
 * Return: Always 0
 */
void free_listint(listint_t *head)
{
	if (!head)
		return;
	free_listint(head->next);
	free(head);
}
