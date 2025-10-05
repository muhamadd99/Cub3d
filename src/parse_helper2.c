/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 08:49:28 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/05 16:27:44 by mbani-ya         ###   ########.fr       */
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
