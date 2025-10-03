/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:00:06 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/10/03 16:28:54 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"
//simple check, file, line, id, all filled

//check no of param, filename and process_check lines
int	parsing(t_parse *parse, int ac, char **av)
{
	int		len;

	if (ac != 2)
		return (1);
	len = ft_strlen(av[1]);
	if (len < 5)
		return (1);
	if (ft_strcmp(".cub", av[1] + len - 4))
		return (1);
	//check line
	parse_file(parse, av);
	return (0);
}

//parsing file content
//p: get_next_line .cub. process each line
int	parse_file(t_parse *p, char **av)
{
	int		fd;
	int		line_no;
	char	*line;

	printf("1a\n"); //d
	line_no = 0;
	fd = open(av[1], O_RDONLY);
	ft_memset(p, 0, sizeof(t_parse));
	while(check_ids_reg(p))
	{
		line = get_next_line_bonus(fd);
		if (!line)
			break ;
		printf("line: %d, line before: %s", line_no, line); //d
		if (check_line(p, line) == 1)
		{
			printf("1b\n"); //d
			return (1);
		}
		free(line);
		line_no++;
	}
	if (!line)
		print_error(p, "not enough argument");
	while(!check_ids_reg(p))
	{
		line = get_next_line_bonus(fd);
		printf("line at i = 0: %s-", line); //d
		if (!line)
			break ;
		if (proc_map(p, line, line_no))
		{
			print_error(p, "wrong map");
			return (1);
		}
		line_no++;
	}
	printf("line_no: %d\n", line_no); //d
	if (p->mapend_pos == 0)
		p->mapend_pos = line_no - 1;
	p->map_flag = 2;
	printf("map: %d, map_end: %d\n", p->map_pos, p->mapend_pos);//d
	close(fd);
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);//debug
	line_no = 0;
	while (p->map_flag == 2)
	{
		printf("a\n");//d
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line_no >= p->map_pos && line_no <= p->mapend_pos)
			if (store_map(p, line, line_no))
			{
				printf("1h\n");//d
				return (1);
			}
		line_no++;
	}
	close(fd);
	printf("line_no2: %d\n", line_no); //d
	if (check_nonspace(line) == 1)
	{
		printf("1g\n");//d
		return (1);
	}
	printf("a\n");//d
	print_param(p);
	return (0);
}

//check all identifier before map in line
//p: skip whitespace
int	check_line(t_parse *parse, char *line)
{
	int	i;

	i = 0;
	while(line[i] && check_ids_reg(parse))
	{
		skip_whitespace(line, &i);
		//case for only emptyline
		if (line[i] == '\0')
			break ;
		if (check_id(parse, line, &i) == 1)
			return (1);
	}
	// i = 0;
	// while(line[i] && check_ids_reg(parse) == 0)
	// {
	// 	if (find_map() == 1)
	// 		map_pos = pos;
	// 	else
	// 		break ;
	// 	if (proc_map(parse, line, &i) == 1)
	// 		return (1);
	// }
	return (0);
}

//check is everything filled or not
//if not filled = 1
int	check_ids_reg(t_parse *p)
{
	int	i;
	
	i = 0;
	while(p->tex_flag[i])
	{
		if (p->tex_flag[i] == 0)
			return(1);
		i++;
	}
	if (p->floor_flag == 0)
		return (1);
	if (p->ceiling_flag == 0)
		return (1);
	return (0);
}

//detect identifier
int	check_id(t_parse *parse, char *line, int *i)
{
	if (line[*i] == '\0')
	{
		//printf("check_id return 1 here\n");//debug
		return (1);
	}
	else if (ft_strncmp("NO ", line + *i, 3) == 0)
		parse_texture(parse, 0, line, i);
	else if (ft_strncmp("SO ", line + *i, 3) == 0)
		parse_texture(parse, 1, line, i);
	else if (ft_strncmp("WE ", line + *i, 3) == 0)
		parse_texture(parse, 2, line, i);
	else if (ft_strncmp("EA ", line + *i, 3) == 0)
		parse_texture(parse, 3, line, i);
	else if (ft_strncmp("F ", line + *i, 2) == 0)
		parse_colour(parse, 'f', line, i);
	else if (ft_strncmp("C ", line + *i, 2) == 0)
		parse_colour(parse, 'c', line, i);
	else
	{
		//printf("check id line check: %c\n",line[*i]);//debug
		//printf("check_id return 1 here2\n");//debug
		return (1);
	}
	return (0);
}

int	check_nonspace(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		printf("char[%d]: %c\n", i, line[i]);//d
		if (!wspace_check(line[i]))
			return (1);
		i++;
	}
	return (0);
}
