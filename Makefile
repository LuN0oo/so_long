# ===================== VARIABLES ===================== #

NAME = so_long

CCW = cc -Wall -Wextra -Werror

SRCS_DIR = srcs/

SOURCE = \
	$(SRCS_DIR)ft_check_valid_map.c \
	$(SRCS_DIR)ft_check_valid_path.c \
	$(SRCS_DIR)ft_end_game.c \
	$(SRCS_DIR)ft_file_to_image.c \
	$(SRCS_DIR)ft_free.c \
	$(SRCS_DIR)ft_key_hook.c \
	$(SRCS_DIR)ft_manage_error.c \
	$(SRCS_DIR)ft_map_ready.c \
	$(SRCS_DIR)ft_movements.c \
	$(SRCS_DIR)ft_print_map.c \
	$(SRCS_DIR)ft_read_map.c \
	$(SRCS_DIR)ft_split.c \
	$(SRCS_DIR)ft_str_utils.c \
	$(SRCS_DIR)so_long.c \
	GNL/get_next_line_utils.c \
	GNL/get_next_line.c

OBJ = $(SOURCE:.c=.o)

MLX_DIR		= mlx
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES	= -I. -I$(MLX_DIR) -Ignl

# ===================== RULES ===================== #

all : $(NAME)

$(NAME) : $(OBJ) $(MLX_LIB)
	$(CCW) $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ===================== CLEAN ===================== #

clean :
	rm -rf $(OBJ) $(GNL_OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re