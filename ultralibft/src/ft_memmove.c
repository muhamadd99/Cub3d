/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:01:56 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/11/22 08:38:41 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t				i;
	size_t				index;
	unsigned char		*destination;
	const unsigned char	*source;

	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (destination == source || len == 0)
		return (dest);
	i = 0;
	if (source < destination)
	{
		while (++i <= len)
		{
			index = len - i;
			destination[index] = source[index];
		}
	}
	else
	{
		while (len-- > 0)
			*(destination++) = *(source++);
	}
	return (dest);
}
/*
#include <stdio.h>

int main()
{
	char	src2 [11] = "HelloWorld";
	char	dest1[14];
	ft_memmove(dest1, src2 + 2, 9);
	printf("%s src \n", src2);
	printf("%s des \n", dest1);
}
*/