/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:03:11 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/09/29 16:50:32 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

//detect identifier
int	check_identifier(t_parse *parse, char *line, int *i)
{
	if (line[*i] == '\0')
		return (1);
	else if (ft_strncmp("NO ", line + *i, 3) == 0)
		parse_texture(parse, 1, line, i);
	else if (ft_strncmp("SO ", line + *i, 3) == 0)
		parse_texture(parse, 2, line, i);
	else if (ft_strncmp("WE ", line + *i, 3) == 0)
		parse_texture(parse, 3, line, i);
	else if (ft_strncmp("EA", line + *i, 3) == 0)
		parse_texture(parse, 4, line, i);
	else if (ft_strncmp("F ", line + *i, 2) == 0)
		parse_colour(parse, 5, line, i);
	else if (ft_strncmp("C ", line + *i, 2) == 0)
		parse_colour(parse, 6, line, i);
	else
		return (1);
	return (0);
}

//check id is what, registered in the array?
//if yes, error
//if no, register in its array.
//iter until space, 
//null term and \n check, substr
void	parse_texture(t_parse *p, int id, char *line, int *i)
{
	int		start;
	char	*new_str;
	
	if (p->tex_flag[id] == 0)
		p->tex_flag[id] = 1;
	else
		print_error(p, "2 Texture detected");
	skip_space(line, i);
	if (line[*i] == '\n' || line[*i] == '\0')
		print_error(p, "not enough param");
	//substr sentence
	start = *i;
	while(wspace_check == 0 && line[*i])
		(*i)++;
	if (line[*i] == '\n' && line[*i] == '\0')
		print_error(p, "not enough param");
	new_str = ft_substr(line, start, *i - start);
	if (!new_str)
		print_error(p, "memory allocation failed");
	p->texture[id] = new_str;
	skip_space(line, i);
	if (line[*i] == '\n')
		(*i)++;
	else
		print_error(p, "not enough param");
}

void	parse_colour()
{
	int		start;
	char	*new_str
	if (p->tex_)
}

void	skip_space(char *line, int *i)
{
	while (wspace_check == 1 && line[*i])
		(*i)++;
}

void	print_error(t_parse *parse, char *message)
{
	printf("Error\n");
	printf("%s\n", message);
	exit(1);
}
