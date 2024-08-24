Library = libft

NAME	= libft.a

CFLAGS	= -Wall -Wextra -Werror

SRC 	=	ft_isalnum.c 	\
			ft_bzero.c 		\
			ft_isalpha.c 	\
			ft_isascii.c 	\
			ft_isdigit.c 	\
			ft_isprint.c 	\
			ft_memcpy.c		\
			ft_memmove.c	\
			ft_memset.c		\
			ft_strlen.c		\
			ft_strlcpy.c 	\
			ft_strlcat.c	\
			ft_toupper.c 	\
			ft_tolower.c 	\
			ft_strrchr.c 	\
			ft_strchr.c		\
			ft_strncmp.c 	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strnstr.c 	\
			ft_atoi.c 		\
			ft_calloc.c		\
			ft_strdup.c		\
			ft_substr.c		\
			ft_strjoin.c 	\
			ft_strtrim.c 	\
			ft_split.c		\
			ft_itoa.c 		\
			ft_strmapi.c 	\
			ft_striteri.c 	\
			ft_putchar_fd.c \
			ft_putstr_fd.c 	\
			ft_putendl_fd.c \
			ft_putnbr_fd.c	\
			print_char.c	\
			print_nbr.c		\
			print_ptr.c		\
			print_str.c		\
			print_uint.c	\
			print_ux.c		\
			print_x.c		\
			printf.c		\
			get_next_line.c \
			get_next_line_utils.c

OBJ			= 	obj
OBJ_MAIN	=	$(SRC:%.c=$(OBJ)/%.o)

$(NAME) : $(OBJ_MAIN)
	ar rcs $(NAME) $(OBJ)/*

$(OBJ)/%.o:	%.c
					@mkdir -p $(OBJ)
					@cc $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJ)/*

fclean: clean
	rm -rf $(NAME)
	rm -rf $(OBJ)

re: fclean all

.PHONY: all, clean, fclean, re
