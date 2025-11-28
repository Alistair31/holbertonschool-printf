#include "main.h"
/**
 * print_unsigned_number - Print an integer (always positive)
 * @n: integer to print
 * Return: number of characters
 */
int print_unsigned_number(int n)
{
	int count = 0;
	unsigned int u;
	char buf[10];
	int i = 0;

	if (n < 0)
	{
		count++;
		u = (unsigned int)(-(long)n);
	}
	else
	{
		u = (unsigned int)n;
	}
	if (u == 0)
	{
		_putchar('0');
		return (count + 1);
	}
	while (u > 0)
	{
		buf[i++] = (char)('0' + (u % 10));
		u /= 10;
	}
	while (i > 0)
	{
		_putchar(buf[--i]);
		count++;
	}
	return (count);
}
