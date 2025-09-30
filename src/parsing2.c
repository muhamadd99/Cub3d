/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:03:11 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/09/30 16:55:54 by mbani-ya         ###   ########.fr       */
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
		parse_colour(parse, 'f', line, i);
	else if (ft_strncmp("C ", line + *i, 2) == 0)
		parse_colour(parse, 'c', line, i);
	else
		return (1);
	return (0);
}

//p: check id is what, registered in the array?
//p: if yes, error
//p: if no, register in its array.
//p: iter until space, 
//p: null term and \n check, substr
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
	while(wspace_check(' ') == 0 && line[*i])
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

//p: check f or c, check if they registered or not
//p: if yes print error. if no flag
//p: skip space, check number. if nbr, iter until space
//p: split and check 3 nbr, skip space & 1 \n, check \n or not
void	parse_colour(t_parse *p, char c, char *line, int *i)
{
	int hexa_col;

	colour_filled(p, c);
	skip_space(line, i);
	if (ft_isdigit((unsigned char)line[*i]) == 0)
		print_error(p, "wrong value for colour");
	hexa_col = colour_digit(p, line, i);
	store_colour(p, c, hexa_col);
	skip_space(line, i);
	if (line[*i] == '\n')
		(*i)++;
	else
		print_error(p, "not enough param");
	
}

void	colour_filled(t_parse *p, char c)
{
	if (c == 'f')
	{
		if (p->floor_flag == 0)
			p->floor_flag = 1;
		else
			print_error(p, "2 Floor colour detected");
	}
	else
	{
		if (p->ceiling_flag == 0)
			p->ceiling_flag = 1;
		else
			print_error(p, "2 ceiling colour detected"); 
	}
}

//process the 230,230,230 part;
//check char nbr only or not
//check 3 group number given or not
//
int	colour_digit(t_parse *p, char *line, int *i)
{
	int		start;
	char	**new_str;
	int		hexa_col;
	int		col_count;

	start = *i;
	while(wspace_check(line[*i]) == 0 && line[*i] == '\0')
		(*i)++; //why need to whitespace check? the moment it come here already digit
	new_str = ft_split(line, ',');
	if (!new_str)
		print_error(p, "malloc");
	//already in array of char but consist of numbers
	if (ft_strdigit(new_str) == 0)
		return (0);
	//check no of colour in array
	col_count = 0;
	while(new_str[col_count])
		col_count++;
	if (col_count != 3)
	{
		free_twop(new_str);
		print_error(p, "not enough colour value");
	}
	hexa_col = colour_digit2(p, new_str);
	return (hexa_col);
}

// start = *i;
// while(wspace_check(line[*i]) == 0 && line[*i] == '\0')
// 	(*i)++;
// rgb = ft_split(line, ',');
// if (!rgb)
// 	print_error(p, "malloc");
// colour_count = 0;
// while(rgb[colour_count])
// {
// 	rgb = ft_atoi(new_str);
// 	colour_count++;
// }
// if (colour_count != 3)
// 	print_error(p, "not enough colour value");

// int	ft_isdigit(char c)
// {
// 	if (c >= '0' && c <= '9')
// 		return (1);
// 	return (0);
// }

void	skip_space(char *line, int *i)
{
	while (wspace_check(line[*i]) == 1 && line[*i])
		(*i)++;
}

void	print_error(t_parse *parse, char *message)
{
	printf("Error\n");
	printf("%s\n", message);
	exit(1);
}
