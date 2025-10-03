/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:07:05 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/12/26 18:53:08 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_store(int fd, char *buf, char *backup)
{
	int		read_line;
	char	*char_temp;

	while (1)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (0);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		char_temp = backup;
		backup = ft_strjoin(char_temp, buf);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (NULL);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*get_next_line_bonus(int fd)
{
	char		*onlyline;
	char		*line;
	char		*buf;
	static char	*backup[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = read_store(fd, buf, backup[fd]);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup[fd] = extract(line);
	onlyline = ft_strdup(line);
	free(line);
	line = NULL;
	return (onlyline);
}
/*
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int	fd1;
	int fd2;

	fd1 = open("test_file1.txt", O_RDONLY);
	fd2 = open("test_file2.txt", O_RDONLY);
	//char *line1 = get_next_line(fd1);
	//printf("%s", line1);
	//free(line1);

	//char *line2 = get_next_line(fd2);
	//printf("%s", line2);
	//free(line2);

	//char *line1_2 = get_next_line(fd1);
	//printf("%s", line1_2);
	//free(line1_2);

	//char *line2_2 = get_next_line(fd2);
	//printf("%s", line2_2);
	//free(line2_2);

	char	*line1 = get_next_line(fd1);
	char	*line2 = get_next_line(fd2);
	while(line1 != NULL || line2 != NULL)
	{
		printf("File1: %s", line1);
		free(line1);
		printf("File2: %s", line2);
		free(line2);
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
	}
	close(fd1);
	close(fd2);
	return (0);
}
*/