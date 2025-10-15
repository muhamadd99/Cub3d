/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:43:42 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/15 12:42:50 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define KEY_ESC     65307
# define KEY_W       119
# define KEY_A       97
# define KEY_S       115
# define KEY_D       100
# define KEY_LEFT    65361
# define KEY_RIGHT   65363
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.05

# define WIN_WIDTH 1980
# define WIN_HEIGHT 1080

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "./../ultralibft/include/libft.h"
# include "./../mlx_linux/mlx.h"
# include <math.h>

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
	void		*mlx;//
	void		*win;//
	char		**map;//
	int			map_width;//
	int			map_height;//
	char		*north_texture;//
	char		*south_texture;//
	char		*west_texture;//
	char		*east_texture;//
	int			floor_color;//
	int			ceiling_color;//
	int			keys[256];
	int			key_left;
	int			key_right;
	t_player	player;
	t_texture	textures[4];
	t_img		img;
}	t_game;

typedef struct s_parse
{
	char		*texture[4];
	int			floor_value;
	int			ceiling_value;
	int			argend_pos;
	int			map_pos;
	int			mapend_pos;
	int			max_height;
	int			max_width;
	int			fd;
	char		**map;
	char		**map_copy;

	int			tex_flag[4];
	int			floor_flag;
	int			ceiling_flag;
	int			map_flag;
	int			player_flag;
	t_player	player;
}	t_parse;

//int		ft_isdigit(char c);
int		wspace_check(char c);
int		parsing(t_parse *parse, int ac, char **av);
int		parse_file(t_parse *p, char **av);
int		check_ids_reg(t_parse *p);
int		check_nonspace(char *line);
int		parse_id_line(t_parse *parse, char *line);
void	free_map(t_parse *p, t_game *g, char **str);
void	free_twop(char **str);
void	skip_whitespace(char *line, int *i);
int		parse_to_exec(t_parse *parse, t_game *game);
void	print_error(t_parse *parse, char *message, char *line);
void	print_exit(t_game *game, char *message);
void	print_param(t_parse *p);
void	print_param2(t_game	*g);
void	print_param_map(int height, int width, char **map);
void	skip_space_not(char *line, int *i, int space);

//texture & colour handling
void	parse_idmap(t_parse *p, char **av);
int		parse_id_key(t_parse *parse, char *line, int *i);
void	parse_id(t_parse *p, char *line, int *line_no);
void	parse_map(t_parse *p, char *line, int *line_no);
void	parse_col_reg(t_parse *p, char c, char *line);
int		parse_col_toint(t_parse *p, char *line, int *i);
int		parse_col_toint2(t_parse *p, char **str);
int		ft_strdigit(char **str);
void	parse_texture(t_parse *p, int id, char *line, int *i);
char	*parse_tex_path(t_parse *p, char *line, int *i);
void	parse_colour(t_parse *p, char c, char *line, int *i);
char	**parse_col_substr(char **str);
void	parse_col_store(t_parse *p, char c, int hexa_col);
char	**parse_col_substr2(char **str);
void	postcheck_map(t_parse *p);

//map handling
int		map_allocate(t_parse *p, char ***map);
int		map_check(t_parse *p, char *line, int line_no);
int		map_char(t_parse *p, char *line, int line_no);
int		flood_fill(t_parse *p, int x, int y);
void	map_copy(t_parse *p, char **map);
int		map_nondigit(t_parse *p, char *line, int line_no, int i);
int		parse_player(t_parse *p, char c, int i, int line_no);
int		map_store(t_parse *p, char **av);
int		map_store_line(t_parse *p, char *line, int line_no);
void	map_fill(t_parse *p, char *line, int line_no);

//muz
void	free_tex(t_game *game);
void	init_image(t_game *game);
void	init_textures(t_game *game);
void	init_mlx(t_parse *parse, t_game *game);
void	load_texture(t_game *game, t_texture *tex, char *path);
int		close_window(t_game *game);
/*render.c*/
int		render_frame(t_game *game);
int		render_movement(t_game *game);
int		render_ceiling_floor(t_game *game);
void	render_walls(t_game *game);
/*dda.c*/
int		init_ray(t_ray *ray);
void	ray_setup(t_game *game, t_ray *ray, int x);
void	ray_cont(t_game *game, t_ray *ray);
void	dda_loop(t_game *game, t_ray *ray);
void	distance_to_wall(t_game *game, t_ray *ray);
/*dda2.c*/
void	pick_texture(t_game *game, t_ray *ray);
void	texture_and_coordinate(t_game *game, t_ray *ray);
void	draw_vertical_line(t_game *game, t_ray *ray, int x);
/*movement.c*/
void	strafe_right(t_game *game);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
/*movement2.c*/
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	strafe_left(t_game *game);

#endif