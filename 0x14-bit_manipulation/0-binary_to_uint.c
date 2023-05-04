#include "holberton.h"
#include <stdio.h>

/**
 * binary_to_uint - function that convert a binary number to an unsigned int
 * @b: string to convert containing the binary number.
 *
 * Return: converted number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num, i;

	if (!b || !*b)
		return (0);

	num = i = 0;
	while (b[i])
	{
		if (b[i] > 49)
			return (0);
		else if (b[i] == 49)
		{
			num <<= 1;
			num += 1;
		}
		else
			num <<= 1;
		i++;
	}
	return (num);
}
