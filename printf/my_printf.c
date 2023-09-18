#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _strlen - calculates the length of a string
 * @str: the string
 * Return: the length of the string
 */
int _strlen(const char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (0);
	}
	return (1 + _strlen(str + 1));
}

/**
 * _printf - mimics the behavior of printf
 * @format: int _strlen(const char *str)the format of the string
 * Return: returns the length of the format string
 */
int _printf(const char *format, ...)
{
	int i = 0;
	char nl = '\n';
	va_list my_entries;

	va_start(my_entries, format);
	while (*(format + i) != '\0')
	{
		if (*(format + i) == '\n')
		{
			write(1, &nl, 1);
		}
		c_fmt_s(format + i, my_entries, &i);
		i++;
	}
	va_end(my_entries);
	return (i);
}

/**
 * c_fmt_s - check formatted string
 * @s: the character or string to be checked
 * @args: the list of entries
 * @i: my counter
 */
void c_fmt_s(const char *s, va_list args, int *i)
{
	char c;
	const char *t;

	if (*(s) == '%')
	{
		switch (*(s + 1))
		{
			case '%':
				write(1, "%", 1);
				break;
			case 'c':
				c = va_arg(args, int);
				write(1, &c, 1);
				break;
			case 's':
				t = va_arg(args, const char*);
				write(1, t, _strlen(t));
				break;
			default:
				break;
		}
		(*i)++;
	}
	else
	{
		write(1, s, 1);
	}
}
