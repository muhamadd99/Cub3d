/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:47:20 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/03/26 14:51:21 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*byte_ptr;
	size_t			i;
	size_t			total_size;

	total_size = nmemb * size;
	if (nmemb == 0 || size == 0)
	{
		ptr = malloc (1);
		return (ptr);
	}
	if (nmemb > (size_t) - 1 / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	byte_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < total_size)
	{
		byte_ptr[i] = 0;
		i++;
	}
	return (ptr);
}
/*
#include <stdio.h>

int main()
{
	int 	*arr;
	size_t	num_elements = 5;

	arr = (int *)ft_calloc(num_elements, sizeof(int));

	if (arr == NULL)
	{
		printf("NULL\n");
		return 1;
	}
	size_t i = 0;
	while (i < num_elements) 
	{
		printf("arr[%zu] = %d\n", i, arr[i]);
		i++;
	}
	free(arr);
}
*/
