#include "main.h"
/**
 * print_char - Print a single character.
 * @args: va_list containing the character to print.
 *
 * Return: Number of characters printed (always 1).
 */
int print_char(va_list args)
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
int print_str(va_list args)
{
char *str = va_arg(args, char *);
int len = 0;

while (str[len])
len++;

write(1, str, len);
return (len);
}