/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:44:28 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/11/22 09:27:48 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (last);
}
/*
#include <stdio.h>
#include <string.h>

int main ()
{
	const	char *str = "HAKAIMI";

	char	ch = 'A';
	char	*result = ft_strrchr(str, ch);

	printf("%s\n", result);
	if (result)
		printf("Found '%c' at %ld\n", ch, result - str);
	else
		printf("not found: \n");
	
	char	ch2 = 'H';
	char	*result2 = ft_strrchr(str, ch2);
	if (result2)
		printf("Found '%c' at %ld\n", ch2, result2 - str);
	else
		printf("Found '%c' at %ld\n", ch2, result2 - str);
	
	char	ch3 = '\0';
	char	*result3 = ft_strrchr(str, ch3);
	if (result3)
		printf("Found null term at %ld\n", result3 - str);
}
*/
