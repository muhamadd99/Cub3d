/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:55:52 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/07 11:44:12 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

void	free_twop(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_map(t_parse *p, char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (i < p->max_height)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	skip_space_not(char *line, int *i, int space)
{
	if (space)
	{
		while (wspace_check(line[*i]) == 1 && line[*i])
			(*i)++;
	}
	else
	{
		while (wspace_check(line[*i]) == 0 && line[*i])
			(*i)++;
	}
}

void	skip_whitespace(char *line, int *i)
{
	while (wspace_check(line[*i]))
		(*i)++;
}

int	wspace_check(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (2);
	if (c == '\n')
		return (3);
	return (0);
}
