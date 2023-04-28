#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
  * list_len - function that returns the number of elements in a linked list_t
  * list
  * @h: const list_t
  *
  * Return: number of elements on the list
  */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}

	return (count);
}
