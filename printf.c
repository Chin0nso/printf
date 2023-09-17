/**
  *File: printf.c
  * _printf: Custom implementation of the printf function.
  * Author: Opara Vivian and Emmanuel Obiajulu Okoye
  *
  * @format: a character string containing format specifiers
  * @...: variable number of arguments to be formatted
  * Return: 0
  */
#include "main.h"
int _printf(const char *format, ...)
{
int character, counter = 0;
char *string;
va_list args;
va_start(args, format);
while (*format != '0')
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
character = va_arg(args, int);
putchar(character);
counter++;
}
else if (*format == 's')
{
string = va_arg(args, char *);
while (*string != '\0')
{
putchar(*string);
string++;
counter++;
}
}
else if (*format == '%')
{
putchar('%');
counter++;
}
else
{
putchar(*format);
counter++;
}
format++;
}
va_end(args);
return (counter);
}
return (0);
}
