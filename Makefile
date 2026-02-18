# ===================== VARIABLES ===================== #

NAME = so_long

CCW = cc -Wall -Wextra -Werror

SRCS_DIR = srcs/

GNL_DIR = GNL/

SOURCE = \
	$(SRCS_DIR)ft_check_valid_map.c \
	$(SRCS_DIR)ft_check_valid_path.c \
	$(SRCS_DIR)ft_free.c \
	$(SRCS_DIR)ft_key_hook.c \
	$(SRCS_DIR)ft_manage_error.c \
	$(SRCS_DIR)ft_map_ready.c \
	$(SRCS_DIR)ft_read_map.c \
	$(SRCS_DIR)ft_split.c \
	$(SRCS_DIR)ft_str_utils.c \
	$(SRCS_DIR)so_long.c

GNL_SOURCES = \
	$(GNL_DIR)get_next_line_utils.c \
	$(GNL_DIR)get_next_line.c \

OBJ = $(SOURCE:.c=.o)

GNL_OBJ = $(GNL_SOURCES:.c=.o)

# ===================== RULES ===================== #

all : $(NAME)

$(NAME) : $(OBJ) $(GNL_OBJ)
	$(CCW) -o $@ $^ -lm

# %.o: %.c
# 	$(CCW) -c $< -o $@

$(SRCS_DIR)%.o: $(SRCS_DIR)%.c
	$(CCW) -c $< -o $@

$(GNL_DIR)%.o: $(GNL_DIR)%.c
	$(CCW) -c $< -o $@

# ===================== CLEAN ===================== #

clean :
	rm -rf $(OBJ) $(GNL_OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re