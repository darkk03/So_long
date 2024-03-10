# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaizenbe <aaizenbe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/10 20:18:08 by aaizenbe          #+#    #+#              #
#    Updated: 2024/03/10 20:18:08 by aaizenbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = \
	ft_hexadecimal.c ft_pointer.c ft_printf.c \
	ft_putchar.c ft_putnbr.c ft_string.c \
	ft_unsigned_int.c get_next_line_utils.c get_next_line.c \

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $(NAME) $?

bonus: $(OBJECTS) $(BOBJECTS)
	$(AR) -r $(NAME) $?

clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
