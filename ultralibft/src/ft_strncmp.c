/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:51:25 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/11/22 09:20:59 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	count = 1;
	if (n == 0)
		return (0);
	while (s1[i] && s2[j] && s1[i] == s2[j] && count < n)
	{
		i++;
		j++;
		count++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>

int main()
{
	const char *str1 = "Yow";
	const char *str2 = "Yol";
	const char *str3 = "Yow";

	printf("%d\n", ft_strncmp(str1, str2, 3));
	printf("%d\n", ft_strncmp(str1, str3, 3));
}
*/
