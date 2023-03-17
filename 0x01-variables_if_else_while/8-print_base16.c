#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**
 * main - print all the numbers of base 16 in lowercase,
 * followed by a new line
 * Return: Always 0 (Success)
 */

int main(void)

{

	int d;
	char low;

	for (d = '0'; d <= '9'; d++)
	putchar(d);

	for (low = 'a'; low <= 'f'; low++)
	putchar(low);
	putchar('\n');

	return (0);
}
