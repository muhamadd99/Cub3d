/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:00:06 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/09 23:18:39 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"
//simple check, file, line, id, all filled
//check no of param, filename and process_check lines
//check file content
//p: get_next_line .cub. process each line
//p: check line by line until all id finish
int	parsing(t_parse *parse, int ac, char **av)
{
	int		len;

	ft_memset(parse, 0, sizeof(t_parse));
	if (ac != 2)
		return (1);
	len = ft_strlen(av[1]);
	if (len < 5)
		return (1);
	if (ft_strcmp(".cub", av[1] + len - 4))
		return (1);
	check_line_idmap(parse, av);
	if (store_map(parse, av))
	{
		printf("here\n"); //d
		return (1);
	}
	postcheck_map(parse);
	return (0);
}

void	check_line_idmap(t_parse *p, char **av)
{
	int		line_no;
	char	*line;

	line = NULL;
	p->fd = open(av[1], O_RDONLY);
	line_no = 0;
	check_ids(p, line, &line_no);
	check_maps(p, line, &line_no);
	close(p->fd);
}

void	check_ids(t_parse *p, char *line, int *line_no)
{
	while (check_ids_reg(p))
	{
		line = get_next_line_bonus(p->fd);
		if (!line)
			break ;
		if (check_line(p, line))
			print_error(p, "Identifier prob", line);
		free(line);
		(*line_no)++;
	}
	if (!line)
		print_error(p, "Arg no/file permit", NULL);
}

//check all identifier before map in line
//null term check for case of only emptyline
//p: skip whitespace
int	check_line(t_parse *parse, char *line)
{
	int	i;

	i = 0;
	while (line[i] && check_ids_reg(parse))
	{
		skip_whitespace(line, &i);
		if (line[i] == '\0')
			break ;
		if (check_id_string(parse, line, &i) == 1)
			return (1);
	}
	return (0);
}

//check is everything filled or not
//if not filled = 1
int	check_ids_reg(t_parse *p)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (p->tex_flag[i] == 0)
			return (1);
		i++;
	}
	if (p->floor_flag == 0)
		return (1);
	if (p->ceiling_flag == 0)
		return (1);
	return (0);
}

// //parsing file content
// //p: get_next_line .cub. process each line
// //p: check line by line until all id finish
// int	parse_file(t_parse *p, char **av)
// {
// 	int		fd;
// 	int		line_no;
// 	char	*line;

// 	line_no = 0;
// 	fd = open(av[1], O_RDONLY);
// 	ft_memset(p, 0, sizeof(t_parse));
// 	while (check_ids_reg(p))
// 	{
// 		line = get_next_line_bonus(fd);
// 		if (!line)
// 			break ;
// 		if (check_line(p, line) == 1)
// 			print_error(p, "Identifier problem");
// 		free(line);
// 		line_no++;
// 	}
// 	if (!line)
// 		print_error(p, "not enough argument");
// 	//check line by line for map
// 	while (!check_ids_reg(p))
// 	{
// 		line = get_next_line_bonus(fd);
// 		if (!line)
// 			break ;
// 		if (proc_map(p, line, line_no))
// 		{
// 			print_error(p, "wrong map");
// 			return (1);
// 		}
// 		free(line);
// 		line_no++;
// 	}
// 	if (p->mapend_pos == 0)
// 		p->mapend_pos = line_no - 1;
// 	p->map_flag = 2;
// 	close(fd);
// 	//store map
// 	fd = open(av[1], O_RDONLY);
// 	line_no = 0;
// 	while (p->map_flag == 2)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		if (line_no >= p->map_pos && line_no <= p->mapend_pos)
// 			if (store_map(p, line, line_no))
// 				return (1);
// 		free(line);
// 		line_no++;
// 	}
// 	close(fd);
// 	//after storing all, check there is player or not. check flood fill.
// 	if (!p->player_flag)
// 		print_error(p, "no player");
// 	if (flood_fill(p, p->player.pos_x, p->player.pos_y))
// 	{
// 		print_error(p, "not closed map");
// 		return (1);
// 	}
// 	if (check_nonspace(line) == 1)
// 		return (1);
// 	//print_param(p); //importantdebug
// 	return (0);
// }