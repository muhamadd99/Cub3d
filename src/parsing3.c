/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:56:15 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/09/30 17:04:01 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

static int	rgb_to_int(unsigned char r, unsigned char g, unsigned char b);

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
	hexa_colour = rgb_to_int(ft_atoi(str[0]), ft_atoi(str[1]), ft_atoi(str[2]));
	return (hexa_colour);
}

void	store_colour(t_parse *p, char c, int hexa_col)
{
	if (c == 'f')
		p->floor_value = hexa_col;
	else
		p->ceiling_value = hexa_col;
}

// int	col_count;

// col_count = 0;
// while(str[col_count])
// {
// 	[col_count] = ft_atoi(new_str[col_count]);
// 	if (rgb[col_count] > 255)
// 	{
// 		free_twop(new_str);
// 		print_error(p, "value is too big");
// 	}
// 	col_count++;
// }

int	rgb_to_int(unsigned char r, unsigned char g, unsigned char b)
{
	return ( 16 << r | 8 << g | b);
}

int	ft_strdigit(char **str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while(str[j])
	{
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

void	free_twop(char **str)
{
	int	i;
	int	j;

	i = 0;
	if (!str)
		return ;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
