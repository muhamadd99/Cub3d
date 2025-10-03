/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:43:39 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/11/22 08:35:55 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ucs;
	size_t			i;

	ucs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ucs[i] == (unsigned char)c)
			return (&ucs[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main()
{
	void *result = ft_memchr("asdasdas", 'd', 5);
	if (result != NULL)
	{
		printf("Found 'd' at %s\n", (char *)result);
	}
	else
	{
		printf ("not found\n");
	}
}
*/
