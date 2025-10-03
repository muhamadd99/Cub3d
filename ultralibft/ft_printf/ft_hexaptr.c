/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:13:07 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/12/18 16:13:07 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex2(unsigned long nbr)//int for error handling.
{
	const char	*hexbase;
	int			length;

	hexbase = "0123456789abcdef";
	length = 0;
	if (nbr == 0)
		length += ft_putchar_length('0');
	if (nbr >= 16)
	{
		length += ft_puthex2(nbr / 16);
		length += ft_puthex2(nbr % 16);
	}
	if (nbr < 16 && nbr != 0)
		length += ft_putchar_length(hexbase[nbr]);
	return (length);
}

int	ft_hexaptr(void *ptr)
{
	int				length;
	unsigned long	pointer;

	pointer = (unsigned long)ptr;
	length = 0;
	if (ptr == 0)
		length += ft_putstr_length("(nil)");
	else
	{
		length += ft_putstr_length("0x");
		length += ft_puthex2(pointer);
	}
	return (length);
}

/*
#include <stdio.h>

int main()
{
    void *ptr = (void *)0x7ffee23b77b0;
    void *null_ptr = NULL;

    ft_hexaptr((unsigned long long)ptr);    // Should print: 0x7ffee23b77b0
    write(1, "\n", 1);
    ft_hexaptr((unsigned long long)null_ptr); // Should print: 0x0
    write(1, "\n", 1);

    return 0;
}
*/