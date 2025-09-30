/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:43:42 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/09/30 17:04:07 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include "./../ultralibft/include/libft.h"

typedef	struct s_parse
{
	char	*texture[4];
	int		floor_value;
	int		ceiling_value;

	int		tex_flag[4];
	int		floor_flag;
	int		ceiling_flag;
} t_parse;

//int		ft_isdigit(char c);
int		wspace_check(char c);
int		parsing(t_parse *parse, int ac, char **av);
int		parse_file(t_parse *parse, char **av);
int		check_line(t_parse *parse, char *line);
int		colour_digit(t_parse *p, char *line, int *i);
int		colour_digit2(t_parse *p, char **str);
void	colour_filled(t_parse *p, char c);
void	free_twop(char **str);
int		ft_strdigit(char **str);
void	skip_whitespace(char *line, int *i);
void	store_colour(t_parse *p, char c, int hexa_col);
int		check_identifier(t_parse *parse, char *line, int *i);
void	parse_texture(t_parse *p, int id, char *line, int *i);
void	parse_colour(t_parse *p, char c, char *line, int *i);
void	skip_space(char *line, int *i);
void	print_error(t_parse *parse, char *message);

#endif