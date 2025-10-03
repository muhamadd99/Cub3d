/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:15:31 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/11/18 17:11:23 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	char str[10] = "asdasd";
	ft_putendl_fd(str, 1);
	int fd = open("outfile.txt", O_CREAT | O_WRONLY, 0644);
	if (fd != -1)
	{
		ft_putendl_fd(str, fd);
		close (fd);
	}
	if (fd == -1)
	{
		perror("error opening file");
	}
}
*/
