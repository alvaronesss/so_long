# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aporras- <aporras-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 15:57:50 by aporras-          #+#    #+#              #
#    Updated: 2024/10/12 16:37:37 by aporras-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = clang

CFLAGS = -Wall -Werror -Wextra

SRC =	get_next_line.c \
			
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	 rm -f $(NAME)

re: fclean all
.PHONY: clean fclean all re