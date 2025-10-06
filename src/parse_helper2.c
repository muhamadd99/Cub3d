/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 08:49:28 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/06 15:30:31 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

void	print_param(t_parse *p)
{
	int	i;
	int	j;

	printf("texture NO: %s\n", p->texture[0]);
	printf("texture SO: %s\n", p->texture[1]);
	printf("texture WE: %s\n", p->texture[2]);
	printf("texture EA: %s\n", p->texture[3]);
	printf("floor_value: %d\n", p->floor_value);
	printf("ceiling_value: %d\n", p->ceiling_value);
	printf("map_pos: %d\n", p->map_pos);
	printf("mapend_pos: %d\n", p->mapend_pos);
	printf("max_width: %d\n", p->max_width);
	printf("max_height: %d\n", p->max_height);
	printf("player dir_x: %f\n", p->player.dir_x);
	printf("player dir_y: %f\n", p->player.dir_y);
	printf("player plane_x: %f\n", p->player.plane_x);
	printf("player plane_y: %f\n", p->player.plane_y);
	printf("player pos_x: %f\n", p->player.pos_x);
	printf("player pos_y: %f\n", p->player.pos_y);
	printf("map\n");
	j = 0;
	while (j < (p->mapend_pos - p->map_pos + 1))
	{
		i = 0;
		while (i < p->max_width)
		{
			printf("%c", p->map[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
	printf("map_copy\n");
	j = 0;
	while (j < (p->mapend_pos - p->map_pos + 1))
	{
		i = 0;
		while (i < p->max_width)
		{
			printf("%c", p->map_copy[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}

void	print_param2(t_game	*g)
{
	int	i;
	int	j;

	printf("execution struct check\n");
	printf("texture NO: %s\n", g->north_texture);
	printf("texture SO: %s\n", g->south_texture);
	printf("texture WE: %s\n", g->west_texture);
	printf("texture EA: %s\n", g->east_texture);
	printf("floor_colour: %d\n", g->floor_color);
	printf("ceiling_colour: %d\n", g->ceiling_color);
	printf("map_width: %d\n", g->map_width);
	printf("map_height: %d\n", g->map_height);
	printf("player dir_x: %f\n", g->player.dir_x);
	printf("player dir_y: %f\n", g->player.dir_y);
	printf("player plane_x: %f\n", g->player.plane_x);
	printf("player plane_y: %f\n", g->player.plane_y);
	printf("player pos_x: %f\n", g->player.pos_x);
	printf("player pos_y: %f\n", g->player.pos_y);
	printf("map\n");
	j = 0;
	while (j < (g->map_height))
	{
		i = 0;
		while (i < g->map_width)
		{
			printf("%c", g->map[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}
