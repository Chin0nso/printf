#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 *_printf - custom printf
* Author: Opara Vivian and Emmanuel Obiajulu Okoye
* @format: a character string containing format specifiers
* @...: variable number of arguments to be formatted
* Return: charcters written
*/
int _printf(const char *format, ...)
{
int chars_written = 0;
va_list args;

va_start(args, format);
while (*format)
{
int len;

if (*format == '%' && format++)
{
switch (*format)
{
case 'd':
case 'i':
{
int n = va_arg(args, int);
char num_str[20];

len = snprintf(num_str, sizeof(num_str), "%d", n);

if (len >= 0)
{
chars_written += write(1, num_str, len);
}
break;
}
default:
{
chars_written += write(1, "%", 1);
break;
}
}
}
else
{
chars_written += write(1, format, 1);
}
format++;
}
va_end(args);
return (chars_written);
}
