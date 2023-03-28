#include "main.h"

/**
 * is_printable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	/* ASCII range of printable characters (32 to 126) */
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map[] = "0123456789ABCDEF";
	/* If ascii_code is negative, make it positive */
	if (ascii_code < 0)
		ascii_code *= -1;
	/* Add the escape sequence for a hex value to the buffer */
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	/* Get the first hexadecimal digit of ascii_code and add it to the buffer */
	buffer[i++] = map[ascii_code / 16];
	/* Get the second hexadecimal digit of ascii_code and add it to the buffer */
	buffer[i] = map[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	/* Check if the character falls within the ASCII range of '0' to '9' */
	if (c >= '0' && c <= '9')
		/* If yes, return 1 to indicate that the character is a digit */
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	/* check if size is long */
	if (size == S_LONG)
		return (num);
	/* check if size is short */
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
