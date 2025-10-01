/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:47:52 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/01 18:09:58 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

int	proc_map(t_parse *p, char *line)
{
	check_map(p, line);
	store_map(p, line);
}

int	check_map(t_parse *p, char *line)
{
	int	pov;
	int	i;

	pov = 0;
	i = 0;
	while (line[i])
	{
		if (ft_isdigit((unsigned char)line[i]) == 0
			&& wspace_check(line[i]) == 1)
		{
			if (pov == 0)
			{
				if (map_reg(p, line[i]) == 0)
					pov = 1;
				else
					return (1);
			}
			else
				return (1);
		}
		else
		{
			
		}
		i++;
	}
	return (0);
}

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

