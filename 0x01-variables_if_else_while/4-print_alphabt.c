#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Print alphabet in lowecase, followed by a new line
 * Return: Always 0 (Success)
 */


int main(void)

{

	char low, e, q;

	e = 'e';
	q = 'q';

	for (low = 'a'; low <= 'z'; low++)
	{
	if (low != e && low != q)
	putchar(low);
	}
	putchar('\n');
	return (0);

}
