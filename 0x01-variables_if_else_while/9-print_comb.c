#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main -print all possible combinations of single-digit numbers
 * Return: Always 0 (Success)
 */

int main(void)

{

	int b;

	for (b = '0'; b <= '9'; b++)
	{
	putchar(b);
	if (b != '9')
	{
	putchar(',');
	putchar(' ');
	}
	}
	putchar('\n');
	return (0);
}
