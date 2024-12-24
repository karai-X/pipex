NAME = pipex
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRC_DIR = ./srcs
SRC = main.c\
		free.c\
		get_path_cmd.c\
		utils.c\

SRCS = $(addprefix $(SRC_DIR), $(SRC))

INC_DIR = ./include
OBJ_DIR = ./objs
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))

LIBFTPRINTF = libftprintf.a
LIBFTPRINTF_PATH = ./ft_printf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF_PATH)/$(LIBFTPRINTF)
		$(CC) $(CFLAGS) $^ -o $@ -I $(INC_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		mkdir -p objs
		$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(LIBFTPRINTF_PATH)/$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_PATH) all

clean:
		make -C $(LIBFTPRINTF_PATH) clean
		rm -f $(OBJS)

fclean: clean
		make -C $(LIBFTPRINTF_PATH) fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
