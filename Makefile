NAME 		= 	client server

CC 			= 	gcc
CFLAGS 		= 	-Wall -Werror -Wextra

LIBFT 		= 	lib/libft/libft.a

SRCS_MAIN	=	src/server.c	\
				src/client.c

OBJ			=	obj
OBJ_MAIN	=	$(SRCS_MAIN:src/%.c=$(OBJ)/%.o)

all: 			$(NAME)

$(LIBFT):
				@cd lib/libft && make -s

$(NAME): $(LIBFT) $(OBJ_MAIN)
	ar rcs $(NAME) $(OBJ)/*

$(OBJ)/%.o:	%.c
					@mkdir -p $(OBJ)
					@cc $(CFLAGS) -c $< -o $@

clean:
	@cd lib/libft && make clean -s
	rm -rf $(OBJ)/*

fclean: clean
	@cd lib/libft && make fclean -s
	rm -rf $(NAME)
	rm -rf $(OBJ)

re: fclean all

.PHONY: all clean fclean re
