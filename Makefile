# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 18:57:52 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/01/05 18:48:14 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CFLAGS = -Wall -Wextra -Werror
libprintf = libft/printf/libftprintf.a
liblibft = libft/libft.a
get_next_line = libft/get_next_line/get_next_line.c libft/get_next_line/get_next_line_utils.c
pipex_tools = pipex_tools_0.c pipex_tools_1.c

all: pipex

pipex: $(liblibft) $(libprintf) $(get_next_line) main.c pipex.c $(pipex_tools)
	cc $(CFLAGS) main.c $(pipex_tools) pipex.c $(get_next_line) $(liblibft) $(libprintf) -o $@

libft/libft.a: libft
	make -C libft

libft/printf/libftprintf.a: libft/printf 
	make -C libft/printf

fclean-libft:
	make fclean -C libft

fclean-printf:
	make fclean -C libft/printf

fclean: fclean-libft fclean-printf