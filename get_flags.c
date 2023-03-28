#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int i, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	/* Loop through the format string, starting from *i+1 */
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		/* Loop through the flag characters */
		for (i = 0; FLAGS_CH[i] != '\0'; i++)
		{
			/* If current character match flag character, set corresponding flag bit */
			if (format[curr_i] == FLAGS_CH[i])
			{
				flags |= FLAGS_ARR[j]; /* Set flag bit using bitwise OR */
				break;
			}
		}
		/* If current character does not match any flag character, break loop */
		if (FLAGS_CH[i] == 0)
			break;
	}

	*i = curr_i - 1; /* Set the updated index value */
	return (flags);
}
