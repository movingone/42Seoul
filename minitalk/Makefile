NAME_CLIENT = client
NAME_SERVER = server

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
SRC_CLIENT = client.c
SRC_SERVER = server.c

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(SRC_CLIENT)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(SRC_CLIENT) -L $(LIBFT_DIR) -lft

$(NAME_SERVER): $(SRC_SERVER)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SRC_SERVER) -L $(LIBFT_DIR) -lft

clean:
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
