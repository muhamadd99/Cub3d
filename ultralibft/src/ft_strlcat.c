/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:53:42 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/11/22 09:15:29 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	while (dst_len < dstsize && dst[dst_len] != '\0')
	{
		dst_len++;
	}
	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (i < (dstsize - dst_len - 1) && src [i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char		dest[10] = "roti";
	const char	*src = "canai";

	size_t	result = ft_strlcat(dest, src, sizeof(dest));

	printf("%s\n", dest);
	printf("%zu\n", result);
	printf("%zu\n", strlen(dest) + strlen(src));

	return (0);
}
*/
