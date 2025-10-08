/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:47:52 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/08 14:15:42 by mbani-ya         ###   ########.fr       */
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
	{
		if (check_map(p, line, line_no))
			return (1);
	}
	return (0);
}

//check map has wrong char or not
//p: if map has char that not space and digit
//p: if NSEW, register. if registered, error.
int	check_map(t_parse *p, char *line, int line_no)
{
	int	i;
	int	digit_flag;

	i = 0;
	digit_flag = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			break ;
		if (line[i] == '0' || line[i] == '1')
			digit_flag = 1;
		if (map_nondigit_case(p, line, line_no, i))
			return (1);
		i++;
		if (i > p->max_width)
			p->max_width = i;
	}
	if (!digit_flag)
		if (p->mapend_pos == 0)
			p->mapend_pos = line_no;
	return (0);
}

//handle non digit char
//p: check non-digit & non-space char
//p: register as player pos if correct char
//p: if wrong char, return 1
int	map_nondigit_case(t_parse *p, char *line, int line_no, int i)
{
	if (line[i] != '0' && line[i] != '1'
		&& wspace_check(line[i]) != 1)
	{
		if (!p->player_flag)
		{
			if (map_reg(p, line[i], i, line_no) == 0)
				p->player_flag = 1;
			else
				return (1);
		}
		else
			return (1);
	}
	return (0);
}

//check NSEW char.
//p: if NSEW register value
//p: if not NSEW return 1
int	map_reg(t_parse *p, char c, int i, int line_no)
{
	t_player	*pl;

	pl = &p->player;
	if (c == 'N')
		pl->dir_y = -1;
	else if (c == 'S')
		pl->dir_y = 1;
	else if (c == 'E')
		pl->dir_x = 1;
	else if (c == 'W')
		pl->dir_x = -1;
	else
		return (1);
	pl->plane_x = -1 * (pl->dir_y * 0.66);
	pl->plane_y = pl->dir_x * 0.66;
	pl->pos_x = i;
	pl->pos_y = line_no - p->map_pos;
	return (0);
}
