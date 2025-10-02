/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:43:42 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/02 16:53:32 by mbani-ya         ###   ########.fr       */
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

typedef	struct s_parse
{
	char	*texture[4];
	int		floor_value;
	int		ceiling_value;
	int		map_pos;
	int		mapend_pos;
	int		max_width;
	char	**map;

	int		tex_flag[4];
	int		floor_flag;
	int		ceiling_flag;
	int		map_flag;
	t_player	*player;
} t_parse;

//int		ft_isdigit(char c);
int		wspace_check(char c);
int		parsing(t_parse *parse, int ac, char **av);
int		parse_file(t_parse *p, char **av);
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
char	**remove_spaces(t_parse *p, char **str);
void	skip_space_not(char *line, int *i, int space);

//map handling
int		proc_map(t_parse *p, char *line, int line_no);
int		check_map(t_parse *p, char *line, int line_no);
int		map_reg(t_parse *p, char c);

#endif