/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 21:21:26 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/06 22:24:36 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

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
