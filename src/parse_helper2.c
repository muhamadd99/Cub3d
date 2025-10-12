/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 08:49:28 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/12 10:09:57 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

void	print_param_map(int height, int width, char **map)
{
	int	i;
	int	j;

	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			printf("%c", map[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}

int	check_nonspace(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (!wspace_check(line[i]))
			return (1);
		i++;
	}
	return (0);
}

void	print_error(t_parse *parse, char *message, char *line)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (parse->texture[i])
			free(parse->texture[i]);
		i++;
	}
	if (parse->map)
		free_map(parse, NULL,parse->map);
	if (parse->map_copy)
		free_map(parse, NULL,parse->map_copy);
	while (line)
	{
		free(line);
		line = get_next_line_bonus(parse->fd);
	}
	printf("Error\n");
	printf("%s\n", message);
	exit(1);
}

void	print_exit(t_game *game, char *message)
{
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game->north_texture);
	free(game->south_texture);
	free(game->west_texture);
	free(game->east_texture);
	free_map(NULL, game, game->map);
	if (message)
	{
		printf("Error\n%s\n", message);
		exit(1);
	}
	exit (0);
}

void	print_param(t_parse *p)
{
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
	print_param_map(p->max_height, p->max_width, p->map);
	printf("map_copy\n");
	print_param_map(p->max_height, p->max_width, p->map_copy);
}

void	print_param2(t_game	*g)
{
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
	print_param_map(g->map_height, g->map_width, g->map);
}
