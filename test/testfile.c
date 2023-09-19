#include "main.h"

int main(void)
{
	unsigned int num = 42;
	int c_p;

	c_p = _printf("Binary representation of %u is %b\n", num, num);

	_printf("Total characters printed: %d\n", c_p);

	return (0);
}
