# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 16:38:11 by isfernan          #+#    #+#              #
#    Updated: 2021/03/22 18:38:38 by isfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= main.c	init.c	utils.c		actions.c	message.c	time.c

OBJS 	= $(SRCS:.c=.o)

FLAGS	= -Wall -Werror -Wextra

NAME	= philo_two

all:		$(OBJS)
			-@gcc -o $(NAME) $(OBJS)

clean:
			-@rm -f $(OBJS)

fclean: 	clean
			-@rm -f $(NAME)

re:	fclean all

.PHONY: all clea fclean re