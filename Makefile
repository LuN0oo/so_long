# ===================== VARIABLES ===================== #

NAME = so_long

CCW = cc -Wall -Wextra -Werror

SRCS_DIR = srcs/

SOURCE = \
	$(SRCS_DIR)so_long.c \
	$(SRCS_DIR)manage_error.c

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