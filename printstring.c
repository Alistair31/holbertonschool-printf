#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * printstring - print a string
 * @args: string to print
 * Return: 1 on success
 */
int printstring(va_list args)
{
	char *s;
	int stg = 0;

	s = va_arg(args, char *);
	if (s == NULL)
	{
		return (-1);
	}
	while (s[stg] != '\0')
	{
		stg++;
	}
	write(1, s, stg);
	return (stg);
}
