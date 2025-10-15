/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:03:11 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/15 12:40:56 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"
//parse texture and colour file

//p: check id is what, registered in the array?
//p: if yes, error
//p: if no, register in its array.
//p: iter until space, 
//p: null term and \n check, substr
void	parse_texture(t_parse *p, int id, char *line, int *i)
{
	char	*new_str;

	if (p->tex_flag[id] == 0)
		p->tex_flag[id] = 1;
	else
		print_error(p, "2 Texture detected", line);
	*i = *i + 3;
	skip_space_not(line, i, 1);
	if (line[*i] == '\n' || line[*i] == '\0')
		print_error(p, "not enough param1", line);
	new_str = parse_tex_path(p, line, i);
	p->texture[id] = new_str;
	skip_whitespace(line, i);
	if (line[*i] != '\0')
		print_error(p, "Texture line invalid", line);
}
// skip_space_not_tabs(line, i, 1, 1);
// if (line[*i] == '\n')
// 	(*i)++;
// else
// 	print_error(p, "not enough param3", line);


char	*parse_tex_path(t_parse *p, char *line, int *i)
{
	int		start;
	int		len;
	char	*new_str;

	start = *i;
	while (wspace_check(line[*i]) == 0 && line[*i])
		(*i)++;
	if (start == *i)
		print_error(p, "not enough param2", line);
	len = *i - start;
	new_str = ft_substr(line, start, len);
	if (!new_str)
		print_error(p, "memory allocation failed", line);
	if (len < 5 || ft_strncmp(new_str + len - 4, ".xpm", 4))
	{
		free(new_str);
		print_error(p, "wrong file for texture", line);
	}
	return (new_str);
}

//p: check f or c, check if they registered or not
//p: if yes print error. if no flag
//p: skip space, check number. if nbr, iter until space
//p: split and check 3 nbr, skip space & 1 \n, check \n or not
void	parse_colour(t_parse *p, char c, char *line, int *i)
{
	int	hexa_col;

	parse_col_reg(p, c, line);
	*i = *i + 2;
	skip_space_not(line, i, 1);
	if (ft_isdigit((unsigned char)line[*i]) == 0)
		print_error(p, "wrong value for colour", line);
	hexa_col = parse_col_toint(p, line, i);
	parse_col_store(p, c, hexa_col);
	while (line[*i])
		(*i)++;
}

void	parse_col_reg(t_parse *p, char c, char *line)
{
	if (c == 'f')
	{
		if (p->floor_flag == 0)
			p->floor_flag = 1;
		else
			print_error(p, "2 Floor colour", line);
	}
	else
	{
		if (p->ceiling_flag == 0)
			p->ceiling_flag = 1;
		else
			print_error(p, "2 Ceiling colour", line);
	}
}

//process the 230,230,230 part;
//check char nbr only or not
//check 3 group number given or not
int	parse_col_toint(t_parse *p, char *line, int *i)
{
	char	**new_str;
	int		hexa_col;

	new_str = ft_split(line + *i, ',');
	if (!new_str)
		print_error(p, "malloc", line);
	if (ft_strdigit(new_str) == 0)
	{
		free_twop(new_str);
		print_error(p, "invalid colour", line);
	}
	new_str = parse_col_substr(new_str);
	if (!new_str)
		print_error(p, "Colour process failed", line);
	hexa_col = parse_col_toint2(p, new_str);
	free_twop(new_str);
	return (hexa_col);
}
