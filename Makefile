NAME = client server

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): client.c server.c
	@make -C libft/
	$(CC) $(CFLAGS) client.c -L./libft/ -lft -o client
	$(CC) $(CFLAGS) server.c -L./libft/ -lft -o server

libft_clean:
					make -C $(LIBFT_LIB) clean

libft_fclean:
					make -C $(LIBFT_LIB) fclean

clean:	libft_clean
	rm -f client.o server.o

fclean: clean libft_fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
