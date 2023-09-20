#include <unistd.h>
#include "main.h"
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
