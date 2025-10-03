/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:37:31 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/12/19 10:33:30 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uputnbr_length(unsigned int n)
{
	int	length;

	length = 0;
	if (n >= 10)
		length += ft_uputnbr_length(n / 10);
	length += ft_putchar_length(n % 10 + '0');
	return (length);
}
/*
#include <stdio.h>

int	main()
{
	printf("\nCharacters Printed: %d\n", ft_uputnbr_length(53435));
}
*/
