/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:56:15 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/15 12:28:35 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

//static int	rgb_to_int(unsigned char r, unsigned char g, unsigned char b);
//parse colour extra file

//check number of splitted
//substr to remove infront and at the back
char	**parse_col_substr(char **str)
{
	int		i;
	char	**new_str;

	i = 0;
	while (str[i])
		i++;
	if (i != 3)
	{
		free_twop(str);
		return (NULL);
	}
	new_str = parse_col_substr2(str);
	if (!new_str)
		return (NULL);
	return (new_str);
}

char	**parse_col_substr2(char **str)
{
	char	**new_str;
	int		i;
	int		j;
	int		start;
	int		error;

	error = 0;
	new_str = malloc(sizeof(char *) * 4);
	if (!new_str)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		j = 0;
		skip_space_not(str[i], &j, 1);
		if (str[i][j] == '\n' || str[i][j] == '\0')
			error = 1;
		start = j;
		skip_space_not(str[i], &j, 0);
		new_str[i] = ft_substr(str[i], start, j - start);
	}
	new_str[3] = NULL;
	if (error == 1)
		return (free_twop(str), free_twop(new_str), NULL);
	return (free_twop(str), new_str);
}

//check number bigger than 255
//cast uchar to prevent big number & negative
//bitshift
int	parse_col_toint2(t_parse *p, char **str)
{
	int				hexa_colour;
	int				i;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	i = 0;
	while (i < 3)
	{
		if (ft_atoi(str[i]) > 255 || ft_atoi(str[i]) < 0)
			print_error(p, "rgb number too big", NULL);
		i++;
	}
	r = (unsigned char)ft_atoi(str[0]);
	g = (unsigned char)ft_atoi(str[1]);
	b = (unsigned char)ft_atoi(str[2]);
	hexa_colour = (r << 16) | (g << 8) | b;
	return (hexa_colour);
}

void	parse_col_store(t_parse *p, char c, int hexa_col)
{
	if (c == 'f')
		p->floor_value = hexa_col;
	else
		p->ceiling_value = hexa_col;
}

//if between the colour other than space and notdigit. exit
//if at the end it is okay.
//if after colour can have whitespace
int	ft_strdigit(char **str)
{
	int	i;
	int	j;

	j = 0;
	while (j < 3)
	{
		i = 0;
		while (str[j][i])
		{
			if (j < 2)
				if (ft_isdigit((unsigned char)str[j][i]) == 0)
					if (str[j][i] != ' ')
						return (0);
			if (j == 2)
				if (ft_isdigit((unsigned char)str[j][i]) == 0)
					if (wspace_check(str[j][i]) == 0)
						return (0);
			i++;
		}
		j++;
	}
	return (1);
}
