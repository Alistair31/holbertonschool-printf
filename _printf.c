#include "main.h"

/**
 * handle_specifier - handles conversion specifiers
 * @specifier: the conversion specifier character
 * @args: va_list of arguments
 *
 * Return: number of characters printed
 */
int handle_specifier(char specifier, va_list args)
{
	char c;
	char *str;
	int count = 0;

	if (specifier == 'c')
	{
		c = va_arg(args, int);
		count = _putchar(c);
	}
	else if (specifier == 's')
	{
		str = va_arg(args, char *);
		count = print_string(str);
	}
	else if (specifier == 'd' || specifier == 'i')
	{
		int n = va_arg(args, int);

		count = printnumber(n);
	}
	else if (specifier == 'u')
	{
		int n = va_arg(args, int);

		count = print_unsigned_number(n);
	}
	else if (specifier == '%')
	{
		count = _putchar('%');
	}
	else
	{
		count += _putchar('%');
		count += _putchar(specifier);
	}

	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: character string containing format specifiers
 *
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}
			count += handle_specifier(format[i], args);
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}

	va_end(args);
	return (count);
}