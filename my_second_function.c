#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
  *print_binary - convert and print unsigned
  *		  integar in binary
  *@num: number
  *Return: numbers of characters printed
  */
int print_binary(unsigned int num)
{
	int printed_c = 0;

	 unsigned int m = 1u << (sizeof(unsigned int) * 8 - 1);

	 int flag = 0;

	while (m > 0)
	{
		char b = (num & m) ? '1' : '0';

		if (b == '1' || flag)
		{
		write(1, &b, 1);
		printed_c++;
		flag = 1;
		}
		m >>= 1;
	}
	if (printed_c == 0)
	{
		write(1, "0", 1);
		printed_c++;
	}
	return (printed_c);
}
