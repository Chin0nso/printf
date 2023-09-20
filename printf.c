#include "main.h"

/**
 * _printf - Custom printf function to handle 'c', 's', and '%'.
 * @format: Format specifier string.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);

while (*format)
{
if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's' ||
*(format + 1) == 'd' || *(format + 1) == 'i' ||
*(format + 1) == '%' || *(format + 1) == 'b' ||
*(format + 1) == 'u' || *(format + 1) == 'o' ||
*(format + 1) == 'x' || *(format + 1) == 'X'))
{
format++;
if (*format == 'c')
{
count += print_char(args);
}
else if (*format == 's')
{
count += print_str(args);
}
else if (*format == 'd' || *format == 'i')
{
count += print_int(args);
}
else if (*format == '%')
{
write(1, "%", 1);
count++;
}
else if (*format == 'b')
{
	print_binary(va_arg(args, unsigned int), &count);
}
else if (*format == 'u')
{
	count += print_uns(args);
}
else if (*format == 'o')
{
	count += print_octal(args);
}
else if (*format == 'x')
{
	count += print_hex_l(args);
}
else if (*format == 'X')
{
	count += print_hex_u(args);
}
else
{
	write(1, "%", 1);
	write(1, format, 1);
	count += 2;
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
