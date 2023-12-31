# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 18:57:52 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/01/09 15:55:31 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CFLAGS = -Wall -Wextra -Werror
libprintf = libft/printf/libftprintf.a
liblibft = libft/libft.a
get_next_line = libft/get_next_line/get_next_line.c libft/get_next_line/get_next_line_utils.c
pipex_tools = pipex_tools_0.c pipex_tools_1.c pipex_tools_2.c
pipex_tools_bonus = pipex_tools_0_bonus.c pipex_tools_1_bonus.c pipex_tools_2_bonus.c

all: $(NAME)

$(NAME): $(liblibft) $(libprintf) $(get_next_line) main.c $(pipex_tools) pipex.h
	cc $(CFLAGS) main.c $(pipex_tools) $(get_next_line) $(liblibft) $(libprintf) -o $@

bonus: $(liblibft) $(libprintf) $(get_next_line) main_bonus.c $(pipex_tools_bonus) pipex_bonus.h
	cc $(CFLAGS) main_bonus.c $(pipex_tools_bonus) $(get_next_line) $(liblibft) $(libprintf) -o $@

libft/libft.a: libft
	make -C libft

libft/printf/libftprintf.a: libft/printf 
	make -C libft/printf

clean-libft:
	make clean -C libft

clean-printf:
	make clean -C libft/printf

fclean-libft:
	make fclean -C libft

fclean-printf:
	make fclean -C libft/printf

fclean-pipex:
	rm -f $(NAME)

fclean-bonus:
	rm -f bonus

clean: clean-libft clean-printf

fclean: fclean-libft fclean-printf fclean-pipex fclean-bonus

re: fclean all