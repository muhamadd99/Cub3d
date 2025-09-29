/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:00:06 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/09/29 15:48:28 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

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

//parsin file content
//p: get_next_line .cub. process each line
void	parse_file(t_parse *parse, char **av)
{
	int		fd;
	char	*line;

	fd = open(av[1]);
	ft_memset(parse, 0, sizeof(parse));
	line = get_next_line(fd);
	if (!line)
		return (1);
	while(line)
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
		if (check_line(parse, line) == 1)
			return (1);
	}
}

//check all identifier before map in line
//p: skip whitespace
int	check_line(t_parse *parse, char *line)
{
	int	i;

	i = 0;
	while(line[i])
	{
		skip_whitespace(line, i);
		if (check_identifier(parse, line, &i) == 1)
			return (1);
		while(wspace_check == 1)
			i++;
		
		i++;
	}
	return (1);
}

void	skip_whitespace(char *line, int *i)
{
	while (wspace_check)
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
