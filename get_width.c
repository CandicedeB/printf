#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;
	/* Loop through characters in format string, start from the index. */
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		/* If current character is digit, then update width accordingly. */
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		/* If current character is '*', get width from va_list and exit */
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		/* If current character is not a digit or '*' then exit the loop. */
		else
			break;
	}
	/* Update the index pointer to the last character processed. */
	*i = curr_i - 1;

	return (width);
}
