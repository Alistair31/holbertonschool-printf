#ifndef MAIN_H
#define MAIN_H

/* Standard libraries */
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/* Main function prototype */
int _printf(const char *format, ...);

/* Helper function prototypes */
int _putchar(char c);
int print_string(char *str);
int printnumber(int n);
int handle_specifier(char specifier, va_list args);

int _printf(const char *format, ...);
#endif
