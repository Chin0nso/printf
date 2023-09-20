#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
  *print_binary - convert and print unsigned
  *		  integar in binary
  *@num: number
  *@count: a pointer
  *Return: void
  */
void print_binary(unsigned int num, int *count)
{
	 unsigned int m = 1u << (sizeof(unsigned int) * 8 - 1);

	 int flag = 0;

	while (m > 0)
	{
		char b = (num & m) ? '1' : '0';

		if (b == '1' || flag)
		{
		write(1, &b, 1);
		(*count)++;
		flag = 1;
		}
		m >>= 1;
	}
	if (*count == 0)
	{
		write(1, "0", 1);
		(*count)++;
	}
}
