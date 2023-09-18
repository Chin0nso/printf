#include "main.h"
/**
 *File: printf.c
 * _printf: Custom implementation of the printf function.
 * Author: Opara Vivian and Emmanuel Obiajulu Okoye
 *
 * @format: a character string containing format specifiers
 * @...: variable number of arguments to be formatted
 * Return: 0
 */
int _printf(const char *format, ...)
{
  int character, counter = 0;
  char *string;
  va_list args;
  va_start(args, format);
  while (*format != '\0')
  {
    if (*format == '%')
    {
      format++;
      if (*format == 'c')
      {
        character = va_arg(args, int);
        write(1, format, 1);
        counter++;
      }
      else if (*format == 's')
      {
        string = va_arg(args, char *);
        while (*string != '\0')
        {
          write(1, format, 1);
          string++;
          counter++;
        }
      }
      else if (*format == '%')
      {
        write(1, format, 1);
        counter++;
      }
      else
      {
        write(1, format, 1);
        counter++;
      }
      format++;
    }
    va_end(args);
    return (counter);
  }
  return (0);
}
