# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kposthum <kposthum@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/06 16:04:34 by kposthum      #+#    #+#                  #
#    Updated: 2023/02/15 12:44:24 by kposthum      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Werror -Wextra
NAME = push_swap
SRCS = push_swap.c	push_make.c	push_short.c	push_shortrev.c	push_empty.c	dec_to_bin.c\
		push_algo2.c	push_algo3.c	push_algo4.c	push_utils.c	push_actions.c

OBJS = push_swap.o	push_make.o	push_short.o	push_shortrev.o	push_empty.o	dec_to_bin.o\
		push_algo2.o	push_algo3.o	push_algo4.o	push_utils.o	push_actions.o

LIBFT = ./libft/libft.a
PRINTF = ./libft/ft_printf/libftprintf.a

all: printf libft $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME) 

$(OBJS): %.o: %.c
	$(CC) -c $^

libft:
	$(MAKE) -C ./libft

printf:
	$(MAKE) -C ./libft/ft_printf

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./libft/ft_printf
	
fclean:
	$(MAKE) clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./libft/ft_printf

re:		fclean all

.PHONY: libft printf clean fclean all re