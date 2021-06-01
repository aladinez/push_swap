# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/01 19:31:26 by aez-zaou          #+#    #+#              #
#    Updated: 2021/06/01 19:31:29 by aez-zaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

BONUS		= checker

GCC			= gcc -Wall -Wextra -Werror

SRCS		= src/push_swap.c			\
				src/quick_sort.c		\
				src/operations1.c		\
				src/operations2.c		\
				src/operations3.c		\
				src/sort_tools.c		\
				src/sort_tools2.c		\
				src/a_to_b.c			\
				src/b_to_a.c			\
				src/error_functions.c	\
				src/ft_atoi.c			\
				src/ft_isdigit.c		\
				src/ft_putchar_fd.c		\
				src/ft_putstr_fd.c		\
				src/ft_strlen.c			\

SRCSBONUS		= src/checker.c				\
				src/checker_tools.c		\
				src/get_next_line.c		\
				src/operations1.c		\
				src/operations2.c		\
				src/operations3.c		\
				src/error_functions.c	\
				src/ft_atoi.c			\
				src/ft_isdigit.c		\
				src/ft_putchar_fd.c		\
				src/ft_putstr_fd.c		\
				src/ft_strlen.c			\

all:	$(NAME)

$(NAME) : $(SRCS)
		$(GCC) $(SRCS) -o $(NAME)

clean :
		rm -f $(NAME) $(BONUS)

fclean : clean
	
re: fclean all

bonus : $(SRCSBONUS)
		$(GCC) $(SRCSBONUS) -o $(BONUS)
