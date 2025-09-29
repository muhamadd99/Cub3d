/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:43:42 by mbani-ya          #+#    #+#             */
/*   Updated: 2025/09/29 15:48:11 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <./../ultralibft/include/libft.h>

typedef	struct s_parse
{
	char	texture[4];
	char	*floor_str;
	char	*ceiling_str;

	int		tex_flag[4];
	int		floor_flag;
	int		ceiling_flag;
} t_parse;

int	wspace_check(char c);

#endif