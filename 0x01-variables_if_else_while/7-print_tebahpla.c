#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main -print lowercase alphabet in reverse, followed by a new line
 * Return: Always 0 (Success)
 */


int main(void)

{

	char low;

	for (low = 'z'; low >= 'a'; low--)
	putchar(low);
	putchar('\n');

	return (0);

}
