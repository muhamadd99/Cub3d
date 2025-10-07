CC = cc

I_DIR = include
LIBFT_DIR = ultralibft
SRC_DIR = src
OBJ_DIR = obj
MLX_DIR = mlx_linux

FLAGS = -Wall -Wextra -Werror
IFLAGS = -I $(I_DIR) -I $(MLX_DIR)
MLXFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
RM = rm -rf

LIBFT_LIB = $(LIBFT_DIR)/ultralibft.a
MLX_LIB = $(MLX_DIR)/libmlx.a

SRC = \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/parse.c \
		$(SRC_DIR)/parse_texture.c \
		$(SRC_DIR)/parse_colour.c \
		$(SRC_DIR)/parse_map.c \
		$(SRC_DIR)/parse_map2.c \
		$(SRC_DIR)/parse_helper.c \
		$(SRC_DIR)/parse_helper2.c \
		$(SRC_DIR)/render.c \
		$(SRC_DIR)/dda.c \
		$(SRC_DIR)/dda2.c \
		$(SRC_DIR)/movement.c \
		$(SRC_DIR)/movement2.c

OBJ = $(SRC:.c=.o)
OBJ_PATH = $(SRC:$(SRC_DIR)/.%c=$(OBJ_DIR)/%.o)

NAME = Cub3D

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_PATH) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(FLAGS) $(IFLAGS) $(OBJ_PATH) $(MLXFLAGS) -o $(NAME) $(LIBFT_LIB)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) $(IFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -s -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)
#rm -f $(MLX_LIB)

re: fclean all

.PHONY: all re clean fclean