#include "main.h"

/** PRINT UNSIGNED NUMBER **/
/**
 * print_unsigned - function
 * @types: type of arguments
 * @buffer: for buffer
 * @flags:  for flags
 * @width: to get width
 * @precision: for this
 * @size: for size
 * Return: returns value
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/** PRINT UNSIGNED NUMBER IN OCTAL  **/
/**
 * print_octal - function
 * @types: for types
 * @buffer: to buffer
 * @flags:  for flags
 * @width: to get width
 * @precision: for pthat
 * @size: for size
 * Return: returns value
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/** PRINT UNSIGNED NUMBER IN HEXADECIMAL **/
/**
 * print_hexadecimal - function
 * @types: for types
 * @buffer: for buffer
 * @flags: to get flag
 * @width: to get width
 * @precision: for precision
 * @size: to get size
 * Return: returns value
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **/
/**
 * print_hexa_upper - function
 * @types: to get lists
 * @buffer: for buffer
 * @flags:  to get flags
 * @width: to get
 * @precision: for precise
 * @size: to get size
 * Return: to get return value
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/** PRINT HEXX NUM IN LOWER OR UPPER **/
/**
 * print_hexa - to print function
 * @types: to get type
 * @map_to: get map
 * @buffer: to buffer
 * @flags: to get flags 
 * @flag_ch: to get flag
 * @width: to get the width
 * @precision: for value
 * @size: for size
 * Return: to return value
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
