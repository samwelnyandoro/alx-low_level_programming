#include "main.h"

/**
 * _puts - prototype that prints a string
 * @str: The string to print
 * Return: void
 */

void _puts(char *str)

{
	for (; *str != '\0'; str++)
	{
	_putchar(*str);
	}
	_putchar('\n');
}
