/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:54:52 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/12/19 10:29:58 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_length(char c)
{
	int	length;

	length = 0;
	write (1, &c, 1);
	length++;
	return (length);
}
/*
#include <stdio.h>

int main()
{
	printf("\n%d\n", ft_putchar_length('c', 0));
	//why i put 0 i dont remember. remove 0 to make it work
}
*/