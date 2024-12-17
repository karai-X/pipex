NAME = libftprintf.a
LIBFT = libft.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRCS = ft_printf.c\
		ft_putnbr_fd_cnt.c\
		ft_putnbr_uint_hex.c\
		ft_putptr.c\
		ft_putstr_fd_cnt.c\

OBJS = $(SRCS:.c=.o)
LIBFT_PATH = ./libft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
		cp $(LIBFT_PATH)/$(LIBFT) $(NAME)
		ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		make -C $(LIBFT_PATH) all

clean:
		make -C $(LIBFT_PATH) clean
		rm -f $(OBJS)

fclean: clean
		make -C $(LIBFT_PATH) fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
