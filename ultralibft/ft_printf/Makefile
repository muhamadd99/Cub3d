# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbani-ya <mbani-ya@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 08:57:41 by mbani-ya          #+#    #+#              #
#    Updated: 2024/12/18 17:09:23 by mbani-ya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

CFILES = ft_putstr_length.c \
			ft_putchar_length.c \
			ft_puthex.c \
			ft_puthex_upper.c \
			ft_putnbr_length.c \
			ft_uputnbr_length.c \
			ft_hexaptr.c \
			ft_printf.c 

OFILES = $(CFILES:.c=.o)

LIBRARY = libftprintf

NAME = $(LIBRARY).a

all: $(NAME)

$(NAME):
		$(CC) $(FLAGS) -c $(CFILES)
		ar -rcs $(NAME) $(OFILES)

clean:
		rm -f $(OFILES)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
