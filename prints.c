#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char matrix = 0, padd = ' ';
	int i = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);
	/* Handle NULL pointer argument */
	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	/* Initialize the buffer */
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[i--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++; /* Increase the length of the buffer as digits are added */
	}
	/* Handle special formatting flags */
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		matrix = '+', length++;
	else if (flags & F_SPACE)
		matrix = ' ', length++;

	i++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, i, length,
		width, flags, padd, matrix, padd_start));
}

/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	/* If null, print "(null)" and return the number of characters printed */
	if (str == NULL)
		return (write(1, "(null)", 6));
	/* Loop through each character in the string */
	while (str[j] != '\0')
	{
		/* If character is printable, add it to the buffer */
		if (is_printable(str[j]))
			buffer[j + offset] = str[j];
		/* If not printable, append hex code to the buffer and update */
		else
			offset += append_hexa_code(str[j], buffer, j + offset);

		j++;
	}

	buffer[j + offset] = '\0';

	return (write(1, buffer, j + offset));
}

/**
 * print_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int j, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	/* get a char pointer argument from the va_list */
	str = va_arg(types, char *);
	/* check if the char pointer is NULL */
	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (j = 0; str[j]; j++)
		;
	/* iterate backwards through the char pointer */
	for (j = j - 1; j >= 0; j--)
	{
		char c = str[j]; /* get the current character */

		write(1, &c, 1); /* write the character to stdout */
		count++;
	}
	return (count);
}
/**
 * print_rot13string - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char k, *str;
	unsigned int n, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	/* retrieve the string argument */
	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	/* loop through the input string */
	for (n = 0; str[n]; n++)
	{
		/* loop through the lookup arrays */
		for (j = 0; in[j]; j++)
		{
			/* if the current input character is found in the lookup array */
			if (in[j] == str[n])
			{
				k = out[j]; /* get the corresponding rotated character */
				write(1, &k, 1); /* print the rotated character */
				count++;
				break;
			}
		} /* if the input character is not found in the lookup array */
		if (!in[j])
		{
			k = str[n]; /* use the original character */
			write(1, &k, 1); /* print the original character */
			count++;
		}
	}
	return (count);
}
