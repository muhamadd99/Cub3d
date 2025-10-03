/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:40:57 by mbani-ya          #+#    #+#             */
/*   Updated: 2024/12/21 17:11:13 by mbani-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *string, ...);
int	ft_puthex_upper(unsigned int nbr);
int	ft_puthex(unsigned int nbr);
int	ft_hexaptr(void *ptr);
int	ft_putchar_length(char c);
int	ft_putstr_length(char *s);
int	ft_putnbr_length(int n);
int	ft_uputnbr_length(unsigned int n);

#endif
