# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/07 21:28:19 by ael-kadh          #+#    #+#              #
#    Updated: 2014/02/27 11:06:59 by ael-kadh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	lem-in
SRC				=	err_and_fill.c main.c liste.c print.c reso.c test.c class.c\
					err_fill_2.c way_searching.c printing.c salle_checking.c
HEAD			=	lemin.h
OBJ				=	$(SRC:.c=.o)
FLAGS			=	-Wall -Wextra -Werror -g3

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[35m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	$(C_GOOD)SUCCESS$(C_NO)
OK				=	$(C_OK)OK$(C_NO)

all : $(NAME)

$(NAME) :
	@gcc $(FLAGS) -I libft/includes -I libft/printf/includes -c $(SRC)
	@gcc $(OBJ) -L libft -lft libft/printf/libftprintf.a -o $(NAME)
	@echo "Compiling" [ $(NAME) ] $(SUCCESS)

clean :
	@rm -f $(OBJ)
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)


fclean : clean
	@rm -f $(NAME)
	@echo "Delete" [ $(NAME) ] $(OK)

re : fclean all

.PHONY: all clean fclean re
