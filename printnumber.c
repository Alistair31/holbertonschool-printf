#include "main.h"
/**
 * printnumber - Print an integer
 * @n: integer to print
 * Return: number of characters
 */
int printnumber(int n)
{
	int count = 0;
	unsigned int u;
	char buf[10];
	int i = 0;

	if (n < 0)
	{
		_putchar('-');
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
		return count + 1;
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
	return count;
}
