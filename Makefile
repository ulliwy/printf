# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/05 13:01:02 by iprokofy          #+#    #+#              #
#    Updated: 2017/10/25 15:04:59 by iprokofy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c\
		ft_putnstr.c\
		ft_putnwstr.c\
		ft_putwchar.c\
		ft_wstrlen.c\
		handle_char.c\
		handle_str.c\
		handle_ptr.c\
		handle_int.c\
		handle_unsigned.c\
		handle_long.c\
		parse_fmt.c
LIBFT = libft/ft_memset.c\
		libft/ft_bzero.c\
		libft/ft_memcpy.c\
		libft/ft_memccpy.c\
		libft/ft_memmove.c\
		libft/ft_memchr.c\
		libft/ft_memcmp.c\
		libft/ft_strlen.c\
		libft/ft_strdup.c\
		libft/ft_strcpy.c\
		libft/ft_strncpy.c\
		libft/ft_strcat.c\
		libft/ft_strncat.c\
		libft/ft_strlcat.c\
		libft/ft_strchr.c\
		libft/ft_strrchr.c\
		libft/ft_strstr.c\
		libft/ft_strnstr.c\
		libft/ft_strcmp.c\
		libft/ft_strncmp.c\
		libft/ft_atoi.c\
		libft/ft_isalpha.c\
		libft/ft_isdigit.c\
		libft/ft_isalnum.c\
		libft/ft_isascii.c\
		libft/ft_isprint.c\
		libft/ft_toupper.c\
		libft/ft_tolower.c\
		libft/ft_memalloc.c\
		libft/ft_memdel.c\
		libft/ft_strnew.c\
		libft/ft_strdel.c\
		libft/ft_strclr.c\
		libft/ft_striter.c\
		libft/ft_striteri.c\
		libft/ft_strmap.c\
		libft/ft_strmapi.c\
		libft/ft_strequ.c\
		libft/ft_strnequ.c\
		libft/ft_strsub.c\
		libft/ft_strjoin.c\
		libft/ft_strtrim.c\
		libft/ft_strsplit.c\
		libft/ft_itoa.c\
		libft/ft_putchar.c\
		libft/ft_putstr.c\
		libft/ft_putendl.c\
		libft/ft_putnbr.c\
		libft/ft_putchar_fd.c\
		libft/ft_putstr_fd.c\
		libft/ft_putendl_fd.c\
		libft/ft_putnbr_fd.c\
		libft/ft_lstnew.c\
		libft/ft_lstdelone.c\
		libft/ft_lstdel.c\
		libft/ft_lstadd.c\
		libft/ft_lstiter.c\
		libft/ft_lstmap.c\
		libft/ft_isspace.c\
		libft/ft_lstback.c\
		libft/ft_strrev.c
FLAGS = -Wall -Wextra -Werror
LIBFTO = $(LIBFT:.c=.o)

all: $(NAME)

libft/%.o: libft/%.c
	gcc -c $(FLAGS) -o $@ $<
		
$(NAME): $(SRC) $(LIBFTO)
	gcc  $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(SRC:.c=.o) $(LIBFTO)
	ranlib $(NAME)

clean:
	rm -f $(SRC:.c=.o)
	rm -f $(LIBFT:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all