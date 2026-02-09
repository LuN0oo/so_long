# ===================== VARIABLES ===================== #

NAME = so_long

CCW = cc -Wall -Wextra -Werror

SRCS_DIR = srcs/

SOURCE = \
	$(SRCS_DIR)so_long.c \
	$(SRCS_DIR)ft_manage_error.c \
	$(SRCS_DIR)ft_read_map.c \
	$(SRCS_DIR)ft_check_valid_map.c \
	$(SRCS_DIR)ft_map_ready.c \
	$(SRCS_DIR)ft_parse_map.c

OBJ = $(SOURCE:.c=.o)

# ===================== RULES ===================== #

all : $(NAME)

$(NAME) : $(OBJ)
	$(CCW) -o $@ $^ -lm

%.o: %.c
	$(CCW) -c $< -o $@

# ===================== CLEAN ===================== #

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re