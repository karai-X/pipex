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

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) libftprintf.a -o $(NAME) -I $(INC_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(LIBFT):
		@make -C $(LIBFT_PATH) all

clean:
		@rm -f $(OBJS)

fclean: clean
		@make clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
