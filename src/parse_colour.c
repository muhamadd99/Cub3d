/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:56:15 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/12 00:16:15 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

//static int	rgb_to_int(unsigned char r, unsigned char g, unsigned char b);
//parse colour extra file

//check number of splitted
//substr to remove infront and at the back
char	**remove_spaces(t_parse *p, char **str)
{
	int		i;
	char	**new_str;

	(void)p;
	i = 0;
	while (str[i])
		i++;
	if (i != 3)
	{
		free_twop(str);
		return (NULL);
	}
	new_str = substr_colour(str);
	if (!new_str)
		return (NULL);
	return (new_str);
}
// start = *i;
// while(wspace_check(line[*i]) == 0 && line[*i] == '\0')
// 	(*i)++;
//
// rgb = ft_split(line, ',');
// if (!rgb)
// 	print_error(p, "malloc");
// colour_count = 0;
// while(rgb[colour_count])
// {
// 	rgb = ft_atoi(new_str);
// 	colour_count++;
// }
// if (colour_count != 3)
// 	print_error(p, "not enough colour value");
//
// int	ft_isdigit(char c)
// {
// 	if (c >= '0' && c <= '9')
// 		return (1);
// 	return (0);
// }
//
// new_str = malloc(sizeof(char *) * 4);
// if (!new_str)
// 	return (NULL);
// i = 0;
// while (str[i])
// {
// 	j = 0;
// 	skip_space_not(str[i], &j, 1);
// 	start = j;
// 	skip_space_not(str[i], &j, 0);
// 	new_str[i] = ft_substr(str[i], start, j - start);
// 	i++;
// }
// new_str[3] = NULL;

char	**substr_colour(char **str)
{
	char	**new_str;
	int		i;
	int		j;
	int		start;
	int		error;

	error = 0;
	new_str = malloc(sizeof(char *) * 4);
	if (!new_str)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		j = 0;
		skip_space_not(str[i], &j, 1);
		if (str[i][j] == '\n' || str[i][j] == '\0')
			error = 1;
		start = j;
		skip_space_not(str[i], &j, 0);
		new_str[i] = ft_substr(str[i], start, j - start);
	}
	new_str[3] = NULL;
	if (error == 1)
		return (free_twop(str), free_twop(new_str), NULL);
	return (free_twop(str), new_str);
}

int	colour_digit2(t_parse *p, char **str)
{
	int				hexa_colour;
	int				i;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	i = 0;
	while (i < 3)
	{
		if (ft_atoi(str[i]) > 255 || ft_atoi(str[i]) < 0)
			print_error(p, "rgb number too big", NULL);
		i++;
	}
	r = (unsigned char)ft_atoi(str[0]);
	g = (unsigned char)ft_atoi(str[1]);
	b = (unsigned char)ft_atoi(str[2]);
	hexa_colour = (r << 16) | (g << 8) | b;
	return (hexa_colour);
}
// hexa_colour = rgb_to_int((unsigned char)ft_atoi(str[0]),
// 		(unsigned char)ft_atoi(str[1]), (unsigned char)ft_atoi(str[2]));
// int	rgb_to_int(unsigned char r, unsigned char g, unsigned char b)
// {
// 	return ((r << 16) | (g << 8) | b);
// }

void	store_colour(t_parse *p, char c, int hexa_col)
{
	if (c == 'f')
		p->floor_value = hexa_col;
	else
		p->ceiling_value = hexa_col;
}

int	ft_strdigit(char **str)
{
	int	i;
	int	j;

	j = 0;
	while (j < 3)
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
