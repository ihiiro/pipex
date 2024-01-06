/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:38:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/06 16:45:42 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/errno.h>
# include "libft/libft.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/printf/ft_printf.h"

int		*unpack_fds(int *fds, int argc, char **argv, int *errnos);
void	check_fds(int *fds, int argc, char **argv, int *errnos);
void	write_fd_to_fd(int fd_read, int fd_write);
int		file_exists(char *filename);
int		is_file(char *symbol);
void	pipeline(int *fds, int *errnos, char **argv, char *paths);
int		strictcmp(char *str0, char *str1);
int		get_heredoc_fd(char *limiter, int *errnos);
char	*get_paths(char **argv);
char	*get_next_path(char **paths, int *path_count);
void	count_chr(char *str, char chr, int *counter);
int		count_2d_str_arr(char **arr);

#endif