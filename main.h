#ifndef main_h
#define main_h

#include <stdarg.h>
/**
 * struct allformat - choose the type
 * @c: type of the string
 * @f: pointer to function to call
 */

typedef struct allformat
{
	char c;
	void (*f)(va_list args);
} allformat;

#endif
