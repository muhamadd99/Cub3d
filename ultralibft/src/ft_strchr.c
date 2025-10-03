/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:44:28 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/03/26 13:28:25 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main ()
{
	const	char *str = "IAMMAD";

	char	ch = 'M';
	char	*result = ft_strchr(str, ch);

	printf("%s\n", result); 
	if (result)
		printf("Found '%c' at %ld\n", ch, result - str);
	else
		printf("not found: \n");
	
	char	ch2 = 'Z';
	char	*result2 = ft_strchr(str, ch2);
	if (result2)
		printf("Found '%c' at %ld\n", ch2, result2 - str);
	else
		printf("Found '%c' at %ld\n", ch2, result2 - str);
	
	char	ch3 = '\0';
	char	*result3 = ft_strchr(str, ch3);
	if (result3)
		printf("Found null term at %ld\n", result3 - str);
}
*/
