#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr = *i + 1;
	int precision = -1;
	/* If there is no period after the current index, return -1 */
	if (format[curr] != '.')
		return (precision);

	precision = 0;

	/* Loop through the format string, starting from index after the period */

	for (curr += 1; format[curr] != '\0'; curr++)
	{
		/* If the current character is a digit, update the precision */
		if (is_digit(format[curr]))
		{
			precision *= 10;
			precision += format[curr] - '0';
		}
		/* If asterisk, get the precision from va_list and exit the loop */
		else if (format[curr] == '*')
		{
			curr++;
			precision = va_arg(list, int);
			break;
		}
		/* If the current character is not a digit or an asterisk, exit the loop */
		else
			break;
	}
	/* Update the current index of the format string and return the precision */
	*i = curr - 1;

	return (precision);
}
