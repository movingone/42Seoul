CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = push_swap.c file1.c file2.c file3.c file4.c file5.c file7.c file8.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: 
	$(MAKE) fclean
	$(MAKE) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

