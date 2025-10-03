/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:11:46 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/12/19 10:16:26 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_checker(char s, va_list *args)
{
	if (s == 's')
		return (ft_putstr_length(va_arg(*args, char *)));
	else if (s == 'd' || s == 'i')
		return (ft_putnbr_length(va_arg(*args, unsigned int)));
	else if (s == 'p')
		return (ft_hexaptr(va_arg(*args, void *)));
	else if (s == 'u')
		return (ft_uputnbr_length(va_arg(*args, unsigned int)));
	else if (s == 'x')
		return (ft_puthex(va_arg(*args, unsigned int)));
	else if (s == 'X')
		return (ft_puthex_upper(va_arg(*args, unsigned int)));
	else if (s == 'c')
		return (ft_putchar_length((char)va_arg(*args, int)));
	else if (s == '%')
		return (ft_putchar_length('%'));
	return (0);
}
//L15.is it really critical to use static int?
//L28.char is promoted to int in variadic fx. 
//L28.so, we handled the char as int & cast it back to char

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		length;

	length = 0;
	i = 0;
	va_start (args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			length += ft_printf_checker(string[i], &args);
		}
		else
			length += ft_putchar_length((char)string[i]);
		i++;
	}
	va_end(args);
	return (length);
}
//L53. length?
/*
#include "ft_printf.h"
#include <stdio.h> // For comparison with the standard printf

int main(void)
{
    int len1, len2;

    // Test case 1: Simple string
    len1 = ft_printf("Hello, %s!\n", "world");
    len2 = printf("Hello, %s!\n", "world");
    printf("ft_printf length: %d, printf length: %d\n", len1, len2);

    // Test case 2: Integers
    len1 = ft_printf("My age is %d and my friend’s age is %i.\n", 25, 30);
    len2 = printf("My age is %d and my friend’s age is %i.\n", 25, 30);
    printf("ft_printf length: %d, printf length: %d\n", len1, len2);

    // Test case 3: Unsigned integers
    len1 = ft_printf("Unsigned number: %u\n", 4294967295U);
    len2 = printf("Unsigned number: %u\n", 4294967295U);
    printf("ft_printf length: %d, printf length: %d\n", len1, len2);

    // Test case 4: Hexadecimal
    len1 = ft_printf("Hex lowercase: %x, Hex uppercase: %X\n", 255, 255);
    len2 = printf("Hex lowercase: %x, Hex uppercase: %X\n", 255, 255);
    printf("ft_printf length: %d, printf length: %d\n", len1, len2);

    // Test case 5: Characters and percentages
    len1 = ft_printf("Character: %c, Percent sign: %%\n", 'A');
    len2 = printf("Character: %c, Percent sign: %%\n", 'A');
    printf("ft_printf length: %d, printf length: %d\n", len1, len2);

    return 0;
}
*/