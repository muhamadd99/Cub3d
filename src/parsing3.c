/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:56:15 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/01 15:46:00 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

static int	rgb_to_int(unsigned char r, unsigned char g, unsigned char b);
//parse colour extra file

int	colour_digit2(t_parse *p, char **str)
{
	int	hexa_colour;
	int i;

	i = 0;
	while(i < 3)
	{
		if(ft_atoi(str[i]) > 255)
			print_error(p, "rgb number too big");
		i++;
	}
	//printf("first number: %d\n", ft_atoi(str[0])); //debug
	//printf("second number: %d\n", ft_atoi(str[1])); //debug
	//printf("third number: %d\n", ft_atoi(str[2])); //debug
	hexa_colour = rgb_to_int((unsigned char)ft_atoi(str[0]),
		(unsigned char)ft_atoi(str[1]), (unsigned char)ft_atoi(str[2]));
	//printf("hexa_color:%d\n", hexa_colour);//debug
	return (hexa_colour);
}

void	store_colour(t_parse *p, char c, int hexa_col)
{
	if (c == 'f')
		p->floor_value = hexa_col;
	else
		p->ceiling_value = hexa_col;
}

int	rgb_to_int(unsigned char r, unsigned char g, unsigned char b)
{
	return ( (r << 16) | (g << 8) | b);
}

int	ft_strdigit(char **str)
{
	int	i;
	int	j;

	j = 0;
	while(str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (ft_isdigit((unsigned char)str[j][i]) == 0)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
