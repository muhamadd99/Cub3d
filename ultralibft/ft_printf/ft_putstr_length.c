/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:24:58 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/12/19 10:32:13 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_strlen(const char *s)
{
	unsigned int	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

int	ft_putstr_length(char *s)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	write (1, s, ft_strlen(s));
	return (ft_strlen(s));
}
/*
#include <stdio.h>

int main()
{
	char	str [11] = "HelloWorld";
	int	length = 0;
	
	printf ("\n%d\n", ft_putstr_length(str));
}
*/
