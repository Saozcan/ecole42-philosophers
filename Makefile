# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 04:45:30 by saozcan           #+#    #+#              #
#    Updated: 2022/05/06 15:17:46 by saozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC =	init_data.c death_check.c forks_situation.c free_exit.c ft_sleep.c \
		get_time.c threads.c display_message.c atoi.c main.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
		rm -rf $(OBJ)

fclean:
		rm -rf $(OBJ) $(NAME)

re: fclean all

.PHONY: all re clean fclean