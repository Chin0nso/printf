#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
  * print_uns - function to print an unsigned integer
  * @args: The va_list containing the unsigned integer argument
  *
  * Return: Number of char printed
  */
int print_uns(va_list args);
int print_uns(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	char buffer[20];

	int c = 0;

	int i = 0;
	int j = i;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (n > 0)
	{
		buffer[i++] = n % 10 + '0';
		n /= 10;
	}

	for (j = i - 1; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		c++;
	}

	return (c);
}

/**
  * print_octal - function to print an unsigned integer as octal
  * @args: va_list containing the unsigned integer argument
  *
  * Return: Number of chars printed
  */
int print_octal(va_list args);
int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[20];
	int c = 0;
	int i = 0;
	int j = i;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (n > 0)
	{
		buffer[i++] = (n % 8) + '0';
		n /= 8;
	}

	for (j = i - 1; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		c++;
	}

	return (c);
}

/**
 * print_hex_l - function to print an unsigned integer as hexadecimal
 * @args: containing the unsigned integer argument
 *
 * Return: Number of characters printed
 */
int print_hex_l(va_list args);
int print_hex_l(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[20];
	int c = 0;
	int i = 0;
	int j = i;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (n > 0)
	{
		int r = n % 16;

		if (r < 10)
			buffer[i++] = r + '0';
		else
			buffer[i++] = r - 10 + 'a';
		n /= 16;
	}

	for (j = i - 1; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		c++;
	}

	return (c);
}

/**
  * print_hex_u - function to print an unsigned integer hexadecimal
  * @args: containing the unsigned integer argument
  *
  * Return: Number of char printed
  */
int print_hex_u(va_list args);
int print_hex_u(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[20];
	int c = 0;
	int i = 0;
	int j = i;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (n > 0)
	{
		int r = n % 16;

		if (r < 10)
			buffer[i++] = r + '0';
		else
			buffer[i++] = r - 10 + 'A';
		n /= 16;
	}

	for (j = i - 1; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		c++;
	}

	return (c);
}












