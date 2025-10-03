/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:43:42 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/03 15:17:15 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "./../ultralibft/include/libft.h"

typedef struct s_player
{
	//where the player is on the map
	double	pos_x;
	double	pos_y;
	//where player facing
	double	dir_x;
	double	dir_y;
	//hard coded FOV value
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	//t_img		img;
	char		**map;
	int			map_width;
	int			map_height;
	//t_player	player;
	//t_texture	textures[4];
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			floor_color;
	int			ceiling_color;
	int			keys[256];
	int			key_left;
	int			key_right;
}	t_game;

typedef	struct s_parse
{
	char	*texture[4];
	int		floor_value;
	int		ceiling_value;
	int		argend_pos;
	int		map_pos;
	int		mapend_pos;
	int		max_width;
	char	**map;

	int		tex_flag[4];
	int		floor_flag;
	int		ceiling_flag;
	int		map_flag;
	t_player	player;
	t_game		*game;
} t_parse;

//int		ft_isdigit(char c);
int		wspace_check(char c);
int		parsing(t_parse *parse, int ac, char **av);
int		parse_file(t_parse *p, char **av);
int		check_ids_reg(t_parse *p);
int		check_nonspace(char *line);
int		check_line(t_parse *parse, char *line);
int		colour_digit(t_parse *p, char *line, int *i);
int		colour_digit2(t_parse *p, char **str);
void	colour_filled(t_parse *p, char c);
void	free_twop(char **str);
int		ft_strdigit(char **str);
void	skip_whitespace(char *line, int *i);
void	store_colour(t_parse *p, char c, int hexa_col);
int		check_id(t_parse *parse, char *line, int *i);
void	parse_texture(t_parse *p, int id, char *line, int *i);
void	parse_colour(t_parse *p, char c, char *line, int *i);
void	print_error(t_parse *parse, char *message);
void	print_param(t_parse *p);
char	**remove_spaces(t_parse *p, char **str);
void	skip_space_not(char *line, int *i, int space);

//map handling
int		proc_map(t_parse *p, char *line, int line_no);
int		check_map(t_parse *p, char *line, int line_no);
int		map_reg(t_parse *p, char c);
int		store_map(t_parse *p, char *line, int line_no);


typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_texture
{
	t_img			img;
	unsigned int	**texture;
}	t_texture;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	t_img	*tex;
}	t_ray;

#endif