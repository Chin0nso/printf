#include "main.h"
#include <unistd.h>
/**
  *_printf - function to handle specifier
  *@format: string that contains formart specifiers
  *@...: number of arguments to be formatted
  *Return: printed_c
  */
int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
	va_list args;
	int printed_c = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printed_c++;
		}
		else
		{
			format++;
			if (*format == 'b')
			{
				unsigned int num = va_arg(args, unsigned int);

				printed_c += print_binary(num);
			}
			else
			{
				write(1, "%", 1);
				write(1, format, 1);
				printed_c += 2;
			}
		}
		format++;
	}
	va_end(args);
	return (printed_c);
}

/**
  *print_binary - convert and print unsigned
  *		  integar in binary
  *@num: number
  *Return: printed_c
  */
int print_binary(unsigned int num);
int print_binary(unsigned int num)
{
	 int printed_c = 0;
	 unsigned int m = 1u << (sizeof(unsigned int) * 8 - 1);

	while (m > 0)
	{
		char b = (num & m) ? '1' : '0';

		write(1, &b, 1);
		printed_c++;
		m >>= 1;
	}
	return (printed_c);
}
