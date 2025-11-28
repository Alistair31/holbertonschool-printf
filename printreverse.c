#include "main.h"
/**
 * printreverse - Print a string in reverse
 * @revstr: string to print
 * Return: number of characters
 */
int printreverse(char *revstr)
{
	int i;
	int len = 0;
	int count = 0;

	if (revstr == NULL)
	{
		return (0);
	}
	while (revstr[len] != '\0')
	{
		len++;
	}
	for (i = len - 1; i >= 0; i--)
	{
		_putchar(revstr[i]);
		count++;
	}
	return (count);
}
