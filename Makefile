CC = cc

I_DIR = include
LIBFT_DIR = ultralibft
SRC_DIR = src
OBJ_DIR = obj

FLAGS = -Wall -Wextra -Werror
IFLAGS = -I $(I_DIR)
RM = rm -rf

LIBFT_LIB = $(LIBFT_DIR)/ultralibft.a

SRC = \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/parsing.c \
		$(SRC_DIR)/parsing2.c \
		$(SRC_DIR)/parsing3.c \
		$(SRC_DIR)/parsing4.c \
		$(SRC_DIR)/parse_helper.c \
		$(SRC_DIR)/parse_helper2.c

OBJ = $(SRC:.c=.o)
OBJ_PATH = $(SRC:$(SRC_DIR)/.%o=$(OBJ_DIR)/%.o)

NAME = cub3D

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_PATH) $(LIBFT_LIB)
	$(CC) $(FLAGS) $(IFLAGS) $(OBJ_PATH) -o $(NAME) $(LIBFT_LIB)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) $(IFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -s -C $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean