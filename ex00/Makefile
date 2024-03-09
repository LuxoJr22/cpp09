# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 12:07:20 by luxojr            #+#    #+#              #
#    Updated: 2024/02/27 19:46:45 by luxojr           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp BitcoinExchange.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = btc
RM = rm -f

OBJS = $(SRCS:.cpp=.o)

.cpp.o:
		$(CC) -c $(CFLAGS) $< -o $@

all:  $(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS)

debug: re

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re debug