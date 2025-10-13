/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:38:16 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/13 15:18:43 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

void	init_mlx(t_parse *parse, t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		print_error(parse, "mlx_init", NULL);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game->win)
		print_error(parse, "mlx_new_window", NULL);
}

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

void	load_texture(t_game *game, t_texture *tex, char *path)
{
	tex->img.img = mlx_xpm_file_to_image(game->mlx, path,
			&tex->img.width, &tex->img.height);
	if (!tex->img.img)
	{
		//printf("Error: failed to load texture %s\n", path);
		print_exit(game, "Fail to load texture");
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

int	close_window(t_game *game)
{
	print_exit(game, NULL);
	return (0);
}
