/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:58:17 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/12 00:20:32 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

int	main(int ac, char **av)
{
	t_parse	parse;
	t_game	game;

	if (parsing (&parse, ac, av) == 1)
		print_error(&parse, "Invalid file", NULL);
	if (parse_to_exec(&parse, &game) == 1)
		return (1);
	init_mlx(&parse, &game);
	init_image(&game);
	init_textures(&game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_loop_hook(game.mlx, render_frame, &game);
	print_param2(&game);//importantdebug
	mlx_loop(game.mlx);
}

//transfer and free value
int	parse_to_exec(t_parse *p, t_game *g)
{
	ft_memset(g, 0, sizeof(t_game));
	g->north_texture = ft_strdup(p->texture[0]);
	g->south_texture = ft_strdup(p->texture[1]);
	g->west_texture = ft_strdup(p->texture[2]);
	g->east_texture = ft_strdup(p->texture[3]);
	g->floor_color = p->floor_value;
	g->ceiling_color = p->ceiling_value;
	g->map_width = p->max_width;
	g->map_height = p->max_height;
	if (allocate_map(p, &g->map) == 1)
		return (1);
	copy_map_array(p, g->map);
	g->player = p->player;
	g->map[(int)g->player.pos_y][(int)g->player.pos_x] = '0';
	g->player.pos_x += 0.5;
	g->player.pos_y += 0.5;
	free_map(p, g,p->map);
	free_map(p, g, p->map_copy);
	free(p->texture[0]);
	free(p->texture[1]);
	free(p->texture[2]);
	free(p->texture[3]);
	return (0);
}
