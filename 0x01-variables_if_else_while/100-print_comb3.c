#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - print all possible different combinations of two digits
 * Return: Always 0 (Success)
 */

int main(void)

{

	int b, y;

	for (b = '0'; b < '9'; b++)
	{

	for (y = b + 1; y <= '9'; y++)
	{
	if (y != b)
	{
	putchar(b);
	putchar(y);
	if (b == '8' && y == '9')
	continue;
	putchar(',');
	putchar(' ');
	}
	}
	}
	putchar('\n');
	return (0);
}
