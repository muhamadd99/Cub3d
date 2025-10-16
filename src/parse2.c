/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:54:25 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/16 07:07:17 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

//detect identifier
int	parse_id_key(t_parse *parse, char *line, int *i)
{
	if (line[*i] == '\0')
		return (1);
	else if (ft_strncmp("NO ", line + *i, 3) == 0)
		parse_texture(parse, 0, line, i);
	else if (ft_strncmp("SO ", line + *i, 3) == 0)
		parse_texture(parse, 1, line, i);
	else if (ft_strncmp("WE ", line + *i, 3) == 0)
		parse_texture(parse, 2, line, i);
	else if (ft_strncmp("EA ", line + *i, 3) == 0)
		parse_texture(parse, 3, line, i);
	else if (ft_strncmp("F ", line + *i, 2) == 0)
		parse_colour(parse, 'f', line, i);
	else if (ft_strncmp("C ", line + *i, 2) == 0)
		parse_colour(parse, 'c', line, i);
	else
		return (1);
	return (0);
}

void	parse_col_substr3(char **str, char ***new_str, int i, int *error)
{
	int	j;
	int	start;

	j = 0;
	skip_space_not(str[i], &j, 1);
	if (str[i][j] == '\n' || str[i][j] == '\0')
		*error = 1;
	start = j;
	skip_space_not(str[i], &j, 0);
	(*new_str)[i] = ft_substr(str[i], start, j - start);
	if (i < 2)
		skip_space_not(str[i], &j, 1);
	if (i == 2)
		skip_whitespace(str[i], &j);
	if (str[i][j] != '\0' && str[i][j] != '\n' && str[i][j] != '\t')
		*error = 1;
}
