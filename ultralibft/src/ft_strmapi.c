/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:41:36 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/11/22 09:19:33 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!f || !s)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>

char to_uppercase(unsigned int i, char c) 
{
    if (c >= 'a' && c <= 'z') 
    {
        return c - 32;  
    }
    return c;
}

int main() {
    char *s = "hello";
    char *modified_str = ft_strmapi(s, to_uppercase);

    if (modified_str != NULL) {
        printf("Original string: %s\n", s);
        printf("Modified string: %s\n", modified_str);
        free(modified_str);  
    } else {
        printf("Memory allocation failed!\n");
    }

    return 0;
}
*/
