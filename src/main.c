/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:58:17 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/06 17:09:35 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

int main(int ac, char **av)
{
	t_parse	parse;
	t_game	game;

	if (parsing (&parse, ac, av) == 1)
		return (1);
	if (parse_to_exec(&parse, &game) == 1)
		return (1);
	//muz
	game.mlx = mlx_init();
	if (!game.mlx)
		print_error(&parse, "mlx_init");
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game.win)
		print_error(&parse, "mlx_new_window");
	init_image(&game);
	init_textures(&game);
	// Hooks
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_hook(game.win, 2, 1L<<0, key_press, &game);
	mlx_hook(game.win, 3, 1L<<1, key_release, &game);
	mlx_loop_hook(game.mlx, render_frame, &game);
	
	//print_param2(&game); //importantdebug
	
	mlx_loop(game.mlx);
}

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
	return (0);
}

//muz
void	init_image(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img,
			&game->img.bits_per_pixel,
			&game->img.line_length,
			&game->img.endian);
	game->img.width = WIN_WIDTH;
	game->img.height = WIN_HEIGHT;
	ft_memset(game->keys, 0, sizeof(game->keys));
	game->key_left = 0;
	game->key_right = 0;

}

//muz
void	load_texture(t_game *game, t_texture *tex, char *path)
{
	tex->img.img = mlx_xpm_file_to_image(game->mlx, path,
			&tex->img.width, &tex->img.height);
	if (!tex->img.img)
	{
		printf("Error: failed to load texture %s\n", path);
		exit(1);                                               //////////check exit fcuntion
	}
	tex->img.addr = mlx_get_data_addr(tex->img.img,
			&tex->img.bits_per_pixel,
			&tex->img.line_length,
			&tex->img.endian);
}

void	init_textures(t_game *game)
{
	load_texture(game, &game->textures[0], game->north_texture);
	load_texture(game, &game->textures[1], game->south_texture);
	load_texture(game, &game->textures[2], game->west_texture);
	load_texture(game, &game->textures[3], game->east_texture);
}

//muz
int	close_window(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}
