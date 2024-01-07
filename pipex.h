/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:38:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/07 14:56:56 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/errno.h>
# include "libft/libft.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/printf/ft_printf.h"

# define READ_END 0
# define WRITE_END 1

int		*unpack_fds(int *fds, int argc, char **argv, int *errnos);
void	check_fds(int *fds, int argc, char **argv, int *errnos);
void	write_fd_to_fd(int fd_read, int fd_write);
void	pipeline(int *fds, int argc, char **argv, char *paths);
int		strictcmp(char *str0, char *str1);
int		get_heredoc_fd(char *limiter, int *errnos);
char	*get_paths(char **argv);
char	*get_next_path(char **paths, int *path_count);
void	count_chr(char *str, char chr, int *counter);
char	*construct_cmd(char *paths, char *cmd);
void	execute_cmd(int fd_read, int fd_write, char **argv);
int		cmp_to_stdin(char *str, char *stdin_str);

#endif