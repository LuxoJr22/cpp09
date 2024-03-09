# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 12:07:20 by luxojr            #+#    #+#              #
#    Updated: 2024/03/04 13:16:48 by luxojr           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp PmergeMe.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = PmergeMe
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