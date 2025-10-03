/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:55:13 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/12/14 21:55:13 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nbr)//int for error handling.
{
	const char	*hexbase;
	int			length;

	hexbase = "0123456789abcdef";
	length = 0;
	if (nbr == 0)
		length += ft_putchar_length('0');
	if (nbr >= 16)
	{
		length += ft_puthex(nbr / 16);
		length += ft_puthex(nbr % 16);
	}
	if (nbr < 16 && nbr != 0)
		length += ft_putchar_length(hexbase[nbr]);
	return (length);
}
/*
#include <stdio.h>
int main(void) {
    unsigned int nbr = 255;

    int chars_printed = ft_puthex(nbr);

    printf("\nCharacters Printed: %d\n", chars_printed);

    return 0;
}
*/