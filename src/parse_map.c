/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:39:18 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/14 15:30:33 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

void	parse_map(t_parse *p, char *line, int *line_no)
{
	while (!check_ids_reg(p))
	{
		line = get_next_line_bonus(p->fd);
		if (!line)
			break ;
		if (map_check(p, line, *line_no))
			print_error(p, "wrong map", line);
		free(line);
		(*line_no)++;
	}
	if (p->mapend_pos == 0)
		p->mapend_pos = (*line_no) - 1;
	p->map_flag = 2;
}

int	map_store(t_parse *p, char **av)
{
	int		line_no;
	char	*line;

	p->fd = open(av[1], O_RDONLY);
	line_no = 0;
	while (p->map_flag == 2)
	{
		line = get_next_line_bonus(p->fd);
		if (!line)
			break ;
		if (line_no >= p->map_pos && line_no <= p->mapend_pos)
			if (map_store_line(p, line, line_no))
				return (1);
		if (line_no > p->mapend_pos && check_nonspace(line) == 1)
			print_error(p, "invalid post-map", line);
		free(line);
		line_no++;
	}
	close(p->fd);
	return (0);
}

void	postcheck_map(t_parse *p)
{
	if (!p->player_flag)
		print_error(p, "no map/player", NULL);
	if (flood_fill(p, p->player.pos_x, p->player.pos_y))
		print_error(p, "not closed map", NULL);
}
