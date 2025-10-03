/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:01:39 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/11/22 09:40:15 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		str = (char *)malloc(sizeof(char) * (j - i + 1));
		if (str)
			ft_strlcpy(str, &s1[i], j - i + 1);
	}
	return (str);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"  

int main() {
    // Example strings for testing
    const char *s1 = "___Hello,_World!___";
    const char *set = "_";  
	// Characters to trim from the beginning and the end

    // Call ft_strtrim
    char *trimmed = ft_strtrim(s1, set);

    // Print the original and trimmed strings
    if (trimmed != NULL) {
        printf("Original: '%s'\n", s1);
        printf("Trimmed: '%s'\n", trimmed);

        // Free the allocated memory for the trimmed string
        free(trimmed);
    } else {
        printf("Memory allocation for trimmed string failed!\n");
    }

    return 0;
}
*/
