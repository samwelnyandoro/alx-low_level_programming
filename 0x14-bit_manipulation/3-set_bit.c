#include "main.h"
/**
 * set_bit - function that sets the value of a bit to 1 at a given index.
 * @n: pointer to a number
 * @index: the index starting from 0 of the bit
 *
 * Return: 1 if it worked or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 64)
		return (-1);
	if (!((*n >> index) & 1))
	{
		*n += 1 << index;
		return (1);
	}
	return (-1);
}
