/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 21:21:26 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/07 13:21:32 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

//p: store map in 2d array
int	store_map(t_parse *p, char *line, int line_no)
{
	if (allocate_map(p, &p->map))
		return (1);
	if (allocate_map(p, &p->map_copy))
		return (1);
	store_map_array(p, line, line_no);
	copy_map_array(p, p->map_copy);
	return (0);
}

// i = 0;
// while (i < p->max_height)
// {
// 	ft_memcpy(p->map_copy[i], p->map[i], p->max_width);
// 	i++;
// }

void	copy_map_array(t_parse *p, char **map)
{
	int	i;

	i = 0;
	while (i < p->max_height)
	{
		ft_memcpy(map[i], p->map[i], p->max_width);
		i++;
	}
}

int	allocate_map(t_parse *p, char ***map)
{
	int		i;

	p->max_height = p->mapend_pos - p->map_pos + 1;
	i = 0;
	if (*map == NULL)
	{
		*map = malloc(sizeof(char *) * (p->max_height));
		if (!*map)
			return (1);
		while (i < p->max_height)
		{
			(*map)[i] = malloc(sizeof(char) * p->max_width);
			if (!(*map)[i])
				return (1);
			i++;
		}
	}
	return (0);
}

void	store_map_array(t_parse *p, char *line, int line_no)
{
	int	i;
	int	height;
	int	len;

	height = line_no - p->map_pos;
	len = ft_strlen(line);
	i = 0;
	while (i < p->max_width)
	{
		if (i < len)
		{
			if (line[i] == ' ' || line[i] == '\n')
				p->map[height][i] = '0';
			else
				p->map[height][i] = line[i];
		}
		else
			p->map[height][i] = '0';
		i++;
	}
}

int	flood_fill(t_parse *p, int x, int y)
{
	if (x >= p->max_width || y >= p->max_height || x < 0 || y < 0)
		return (1);
	if (p->map_copy[y][x] == '2' || p->map_copy[y][x] == '1')
		return (0);
	p->map_copy[y][x] = '2';
	if (flood_fill(p, x + 1, y) || flood_fill(p, x - 1, y)
		|| flood_fill(p, x, y + 1) || flood_fill(p, x, y - 1))
		return (1);
	return (0);
}
