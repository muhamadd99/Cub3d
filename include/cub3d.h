/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:43:42 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/09/29 21:42:25 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <./../ultralibft/include/libft.h>

typedef	struct s_parse
{
	char	texture[4];
	char	*floor_str;
	char	*ceiling_str;

	int		tex_flag[4];
	int		floor_flag;
	int		ceiling_flag;
} t_parse;

int		wspace_check(char c);
int		parsing(t_parse *parse, int ac, char **av);
void	parse_file(t_parse *parse, char **av);
int		check_line(t_parse *parse, char *line);
void	skip_whitespace(char *line, int *i);
int		check_identifier(t_parse *parse, char *line, int *i);
void	parse_texture(t_parse *p, int id, char *line, int *i);
void	parse_colour(t_parse *p, char c, char *line, int *i);
void	skip_space(char *line, int *i);
void	print_error(t_parse *parse, char *message);


#endif