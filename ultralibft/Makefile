CC = cc
LIBRARY	= ultralibft.a

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
FTPRINTF_DIR = ft_printf

CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I $(INC_DIR) -I $(FTPRINTF_DIR)

FTPRINTF_LIB = $(FTPRINTF_DIR)/libftprintf.a

SRC 	= \
	$(SRC_DIR)/ft_strlen.c \
	$(SRC_DIR)/ft_memmove.c \
	$(SRC_DIR)/ft_memcpy.c \
	$(SRC_DIR)/ft_strlcpy.c \
	$(SRC_DIR)/ft_strlcat.c \
	$(SRC_DIR)/ft_isalpha.c \
	$(SRC_DIR)/ft_isdigit.c \
	$(SRC_DIR)/ft_isalnum.c \
	$(SRC_DIR)/ft_isascii.c \
	$(SRC_DIR)/ft_isprint.c \
	$(SRC_DIR)/ft_memset.c \
	$(SRC_DIR)/ft_bzero.c \
	$(SRC_DIR)/ft_toupper.c \
	$(SRC_DIR)/ft_tolower.c \
	$(SRC_DIR)/ft_strchr.c \
	$(SRC_DIR)/ft_strrchr.c \
	$(SRC_DIR)/ft_strcmp.c \
	$(SRC_DIR)/ft_strncmp.c \
	$(SRC_DIR)/ft_memchr.c \
	$(SRC_DIR)/ft_memcmp.c \
	$(SRC_DIR)/ft_strnstr.c \
	$(SRC_DIR)/ft_atoi.c \
	$(SRC_DIR)/ft_calloc.c \
	$(SRC_DIR)/ft_strdup.c \
	$(SRC_DIR)/ft_substr.c \
	$(SRC_DIR)/ft_strjoin.c \
	$(SRC_DIR)/ft_strtrim.c \
	$(SRC_DIR)/ft_split.c \
	$(SRC_DIR)/ft_itoa.c \
	$(SRC_DIR)/ft_strmapi.c \
	$(SRC_DIR)/ft_striteri.c \
	$(SRC_DIR)/ft_putchar_fd.c \
	$(SRC_DIR)/ft_putstr_fd.c \
	$(SRC_DIR)/ft_putendl_fd.c \
	$(SRC_DIR)/ft_lstnew.c \
	$(SRC_DIR)/ft_lstadd_back.c \
	$(SRC_DIR)/ft_lstadd_front.c \
	$(SRC_DIR)/get_next_line_bonus.c \
	$(SRC_DIR)/get_next_line.c
 #$(SRC_DIR)/get_next_line_utils_bonus.c
 #$(SRC_DIR)/get_next_line_utils.c 

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) 
#change the cfiles files extension to .o/. store object files in obj_dir

NAME = $(LIBRARY)

all: $(NAME)

$(NAME): $(OBJ) $(FTPRINTF_LIB)
	ar -rcs $(LIBRARY) $(OBJ)

$(FTPRINTF_LIB):
	make -C $(FTPRINTF_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C $(FTPRINTF_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FTPRINTF_DIR) fclean

re: fclean all

.PHONY: all, clean, fclean, re
