# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 19:33:40 by isfernan          #+#    #+#              #
#    Updated: 2021/03/22 20:23:50 by isfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= main.c	init.c	utils.c		actions.c	message.c	time.c

OBJS 	= $(SRCS:.c=.o)

FLAGS	= -Wall -Werror -Wextra

NAME	= philo_three

all:		$(OBJS)
			-@gcc -o $(NAME) $(OBJS)

clean:
			-@rm -f $(OBJS)

fclean: 	clean
			-@rm -f $(NAME)

re:	fclean all

.PHONY: all clea fclean re