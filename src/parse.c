/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:00:06 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/13 12:50:35 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"
//simple check, file, line, id, all filled
//check no of param, filename and process_check lines
//check file content
//p: get_next_line .cub. process each line
//p: check line by line until all id finish
int	parsing(t_parse *parse, int ac, char **av) //parse
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
	parse_idmap(parse, av);
	if (map_store(parse, av))
		return (1);
	postcheck_map(parse);
	return (0);
}

void	parse_idmap(t_parse *p, char **av)
{
	int		line_no;
	char	*line;

	line = NULL;
	p->fd = open(av[1], O_RDONLY);
	line_no = 0;
	parse_id(p, line, &line_no);
	parse_map(p, line, &line_no);
	close(p->fd);
}

void	parse_id(t_parse *p, char *line, int *line_no)
{
	while (check_ids_reg(p))
	{
		line = get_next_line_bonus(p->fd);
		if (!line)
			break ;
		if (parse_id_line(p, line))
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
int	parse_id_line(t_parse *parse, char *line)
{
	int	i;

	i = 0;
	while (line[i] && check_ids_reg(parse))
	{
		skip_whitespace(line, &i);
		if (line[i] == '\0')
			break ;
		if (parse_id_key(parse, line, &i) == 1)
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
