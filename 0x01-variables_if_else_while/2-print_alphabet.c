#include <stdio.h>

/**
 * main -prints alphabet in loercase, followed by a new line
 * Return:Always Succes
 */

int main(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
		putchar(c);
	putchar('\n');
	return (0);
}
