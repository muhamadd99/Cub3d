/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:47:52 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/02 17:12:17 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

//check meet map or not
//if havent have whitespace skip
//if found, now whitespace just check
//once validated, store everything
int	proc_map(t_parse *p, char *line, int line_no)
{
	int	i;

	i = 0;
	if (p->map_flag == 0)
	{
		skip_whitespace(line, &i);
		if (line[i] == '\0')
			return (0);
		else if (ft_isdigit(line[i]) == 1)
		{
			p->map_flag = 1;
			p->map_pos = line_no;
		}
		else
			return (1);
	}
	if (p->map_flag == 1)
		if (check_map(p, line, line_no))
			return (1);
	// //if map validated, then store map
	// if (p->map_flag == 2)
	// 	if (store_map(p, line))
	// 		return (1);
}

//check map has wrong char or not
//p: if map has char that not space and digit
//p: if NSEW, register. if registered, error.
int	check_map(t_parse *p, char *line, int line_no)
{
	int	pov;
	int	i;
	int	digit_flag;

	pov = 0;
	i = 0;
	digit_flag = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1'
			|| wspace_check(line[i]) == 1)
		{
			digit_flag = 1;
			if (!pov)
			{
				if (map_reg(p, line[i]) == 0)
					pov = 1;
				else
					return (1);
			}
			else
				return (1);
		}
		i++;
		if (i > p->max_width)
			p->max_width = i;
	}
	if (!digit_flag)
		if (p->mapend_pos == 0)
			p->mapend_pos = line_no;
	return (0);
}

//check NSEW char.
//p: if NSEW register value
//p: if not NSEW return 1
int	map_reg(t_parse *p, char c)
{
	t_player	*pl;

	pl = p->player;
	if (c =='N') 
	{
		pl->dir_x = 0;
		pl->dir_y = -1;
	}
	else if (c == 'S')
	{
		pl->dir_x = 0;
		pl->dir_y = 1;
	}
	else if (c == 'E')
	{
		pl->dir_x = 1;
		pl->dir_y = 0;
	}
	else if (c == 'W')
	{
		pl->dir_x = 0;
		pl->dir_x = -1;
	}
	else
		return (1);
	return (0);
}

//p: store map in 2d array
int	store_map(t_parse *p, char *line, int line_no)
{
	int		i;
	int		max_width;
	int		max_height;
	char	**map;
	int		height;

	max_height = p->mapend_pos - p->map_pos + 1;
	max_width = p->max_width;
	i = 0;
	if (p->map == NULL)
	{
		p->map = malloc(sizeof(char) * (max_height));
		if (!p->map)
			return (NULL);
		while(p->map[i])
		{
			p->map[i] = malloc(sizeof(char) * max_width);
			if (!p->map[i])
				return (NULL);
			i++;
		}
	}
	height = line_no - p->map_pos;
	i = 0;
	while(p->map[height][i])
	{
		p->map[height][i] = line[i];
		i++;
	}
	return (0);
}
