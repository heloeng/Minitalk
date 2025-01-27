# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: helde-so <helde-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 10:16:57 by helde-so          #+#    #+#              #
#    Updated: 2025/01/27 10:17:01 by helde-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

NAME_C = client
NAME_S = server

SRCS_C = $(NAME_C).c
SRCS_S = $(NAME_S).c
	
OBJS_C = $(SRCS_C:.c=.o)
OBJS_S = $(SRCS_S:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME) 

minitalk: $(NAME_C) $(NAME_S)

server: $(OBJS_S) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_S) -o $(NAME_S) -L$(LIBFT_DIR) -lft

client: $(OBJS_C) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_C) -o $(NAME_C) -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS_C) $(OBJS_S)
	make -C libft clean

fclean: clean
	rm -f $(NAME_C) $(NAME_S)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re