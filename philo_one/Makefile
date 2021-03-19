# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 17:57:43 by isfernan          #+#    #+#              #
#    Updated: 2021/03/19 12:56:13 by isfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= main.c	init.c	utils.c		actions.c	message.c

OBJS 	= $(SRCS:.c=.o)

FLAGS	= -Wall -Werror -Wextra

NAME	= philo_one

all:		$(OBJS)
			-@gcc -o $(NAME) $(OBJS)

clean:
			-@rm -f $(OBJS)

fclean: 	clean
			-@rm -f $(NAME)

re:	fclean all

.PHONY: all clea fclean re