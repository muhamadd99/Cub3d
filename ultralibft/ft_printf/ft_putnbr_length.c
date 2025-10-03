/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:37:31 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/12/19 10:33:10 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_length(int n)
{
	int	length;

	length = 0;
	if (n == -2147483648)
		return (ft_putstr_length("-2147483648"));
	if (n < 0)
	{
		length += write (1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		length += ft_putnbr_length(n / 10);
	length += ft_putchar_length(n % 10 + '0');
	return (length);
}
/*
#include <stdio.h>

int	main()
{
	printf("\nCharacters Printed: %d\n", ft_putnbr_length(-53435));
}
*/
