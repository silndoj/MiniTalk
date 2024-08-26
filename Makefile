CFLAGS 		= 	-Wall -Werror -Wextra

LIBFT 		= 	lib/libft/libft.a

all:
	@cd lib/libft && make -s
	@cc $(CFLAGS) src/server.c $(LIBFT) -o server
	@cc $(CFLAGS) src/client.c $(LIBFT) -o client

clean:
	@cd lib/libft && make clean -s

fclean: clean
	@cd lib/libft && make fclean -s
	rm -rf server client

re: fclean all

.PHONY: all clean fclean re
