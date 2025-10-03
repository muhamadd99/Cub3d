/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:11:22 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/11/22 08:57:16 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i] != '\0')
		{
			f(i, s + i);
			i++;
		}
	}
}
/*
#include <stdio.h>

void	ft_toupper2(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
	{
		*c = (*c - 'a' + 'A');
	}
}

int	main()
{
	char str [11] = "helloworld";
	printf("%s\n", str);
	ft_striteri(str, ft_toupper2);
	printf("%s\n", str);
}
*/
