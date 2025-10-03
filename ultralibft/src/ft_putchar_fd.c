/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:13:32 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/11/13 12:08:51 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

/*
#include <fcntl.h>
#include <unistd.h>

int	main()
{
	ft_putchar_fd('c', 1);
	int	fd;

	fd = open("outfile.txt", O_CREAT | O_WRONLY, 0644);
	if (fd != -1)
	{
		ft_putchar_fd('B', fd);
		close(fd);
	}
}
*/
