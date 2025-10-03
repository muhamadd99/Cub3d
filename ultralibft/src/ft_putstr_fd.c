/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:40:51 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/11/18 17:10:06 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write (fd, s, ft_strlen(s));
}
/*
#include <fcntl.h>

int	main()
{
	char	str [11] = "WASUP BOISZ";
	ft_putstr_fd(str, 1);
	int	fd;

	fd = open("outfile.txt", O_CREAT | O_WRONLY, 0644);
	if (fd != -1)
	{
		ft_putstr_fd(str, fd);
		close (fd);
	}
}
*/
