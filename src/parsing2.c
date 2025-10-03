/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:03:11 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/03 17:34:38 by mbani-ya         ###   ########.fr       */
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
	int		start;
	int		len;
	char	*new_str;
	
	//printf("%d\n", p->tex_flag[0]);//debug
	if (p->tex_flag[id] == 0)
		p->tex_flag[id] = 1;
	else
		print_error(p, "2 Texture detected");
	*i = *i + 3;
	skip_space_not(line, i, 1);
	if (line[*i] == '\n' || line[*i] == '\0')
		print_error(p, "not enough param1");
	//substr identifier
	start = *i;
	while(wspace_check(line[*i]) == 0 && line[*i])
		(*i)++;
	if (start == *i)
		print_error(p, "not enough param2");
	len = *i - start;
	new_str = ft_substr(line, start, len);
	if (!new_str)
		print_error(p, "memory allocation failed");
	if (len < 5 || ft_strncmp(new_str + len - 4, ".xpm", 4))
		print_error(p, "wrong file for texture");
	p->texture[id] = new_str;
	skip_space_not(line, i, 1);
	//handle path 
	if (line[*i] == '\n')
		(*i)++;
	else
		print_error(p, "not enough param3");
}

//p: check f or c, check if they registered or not
//p: if yes print error. if no flag
//p: skip space, check number. if nbr, iter until space
//p: split and check 3 nbr, skip space & 1 \n, check \n or not
void	parse_colour(t_parse *p, char c, char *line, int *i)
{
	int hexa_col;

	colour_filled(p, c);
	*i = *i + 2;
	skip_space_not(line, i, 1);
	//printf("before store colour: %c\n", line[*i]);//debug
	if (ft_isdigit((unsigned char)line[*i]) == 0)
		print_error(p, "wrong value for colour");
	hexa_col = colour_digit(p, line, i);
	store_colour(p, c, hexa_col);
	//printf("hexa_col: %d\n", hexa_col);//debug
	while(line[*i])
		(*i)++;
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
	new_str = ft_split(line + *i, ',');
	if (!new_str)
		print_error(p, "malloc");
	new_str = remove_spaces(p, new_str);
	//int k = 0;//debug
	//while (new_str[k])//debug
	//	printf("newstr: %s-\n", new_str[k++]);//debug
	//already in array of char but consist of numbers
	if (ft_strdigit(new_str) == 0)
	{
		//printf("strdigit return 0\n");//debug
		return (0);
	}
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

//check number of splitted
char	**remove_spaces(t_parse *p, char **str)
{
	int	i;
	int	j;
	int	start;
	char **new_str;

	i = 0;
	while(str[i])
		i++;
	if (i != 3)
	{
		free_twop(str);
		print_error(p, "not enough colour value");
	}
	new_str = malloc(sizeof(char *) * 4);
	if (!new_str)
		return (NULL);
	i = 0;
	while(str[i])
	{
		j = 0;
		skip_space_not(str[i], &j, 1);
		start = j;
		skip_space_not(str[i], &j, 0);
		new_str[i] = ft_substr(str[i], start, j - start);
		i++;
	}
	return(new_str);
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