/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:51:25 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/01 08:24:12 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//not libft validated
int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
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
