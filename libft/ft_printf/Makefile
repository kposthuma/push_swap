# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kposthum <kposthum@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/19 13:36:56 by kposthum      #+#    #+#                  #
#    Updated: 2023/02/15 11:39:51 by kposthum      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Werror -Wextra
NAME = libftprintf.a
SRCS = 	ft_printf.c	ft_printwrite.c	ft_putptr.c
OBJS = ft_printf.o	ft_printwrite.o	ft_putptr.o

all: $(NAME)

$(NAME): $(OBJS)
	ar -cr $(NAME) $(OBJS)

$(OBJS): %.o: %.c
	$(CC) -c $^

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:		fclean all

.PHONY: clean fclean all re