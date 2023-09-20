#ifndef MAIN_H
#define MAIN_H

/* Preprocessor Directive */
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/* Prototypes */
int _printf(const char *format, ...);
int print_char(va_list args);
int print_str(va_list args);
int print_int(va_list args);
void print_binary(unsigned int num, int *count);
#endif /* MAIN_H */
