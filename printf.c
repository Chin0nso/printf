#include "main.h"

/**
 * print_char - Print a single character.
 * @args: va_list containing the character to print.
 *
 * Return: Number of characters printed (always 1).
 */
static int print_char(va_list args)
{
int c = va_arg(args, int);
write(1, &c, 1);
return (1);
}

/**
 * print_str - Print a string.
 * @args: va_list containing the string to print.
 *
 * Return: Number of characters printed.
 */
static int print_str(va_list args)
{
char *str = va_arg(args, char *);
int len = 0;

while (str[len])
len++;

write(1, str, len);
return (len);
}

/**
 * _printf - Custom printf function to handle 'c', 's', and '%'.
 * @format: Format specifier string.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);

while (*format)
{
if (*format == '%')
{
if ((*(format + 1) == 'c' || *(format + 1) == 's' || *(format + 1) == '%'))
{
format++;
if (*format == 'c')
count += print_char(args);
else if (*format == 's')
count += print_str(args);
else if (*format == '%')
{
write(1, "%", 1);
count++;
}
}
}

else
{
write(1, format, 1);
count++;
}
format++;
}

va_end(args);
return (count);
}
