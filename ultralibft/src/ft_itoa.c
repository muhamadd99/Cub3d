/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:11:06 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/11/22 08:34:56 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_number_size(int number)
{
	unsigned int	length;

	length = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		length += 1;
	while (number != 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char			*string;
	unsigned int	number;
	unsigned int	length;

	length = ft_number_size(n);
	string = (char *)malloc(sizeof(char) * (length + 1));
	if (string == NULL)
		return (NULL);
	if (n < 0)
	{
		string[0] = '-';
		number = -n;
	}
	else
		number = n;
	if (number == 0)
		string[0] = '0';
	string[length] = '\0';
	while (number != 0)
	{
		string[length - 1] = (number % 10) + '0';
		number = number / 10;
		length--;
	}
	return (string);
}
/*#include <stdio.h>

int main() {
    // Test with a positive number
    int num1 = 12345;
    char *str1 = ft_itoa(num1);
    if (str1 != NULL) {
        printf("ft_itoa(%d) = %s\n", num1, str1);
        free(str1);  // Don't forget to free the memory
    }

    // Test with a negative number
    int num2 = -98765;
    char *str2 = ft_itoa(num2);
    if (str2 != NULL) {
        printf("ft_itoa(%d) = %s\n", num2, str2);
        free(str2);  // Don't forget to free the memory
    }

    // Test with zero
    int num3 = 0;
    char *str3 = ft_itoa(num3);
    if (str3 != NULL) {
        printf("ft_itoa(%d) = %s\n", num3, str3);
        free(str3);  // Don't forget to free the memory
    }

    return 0;
}
*/