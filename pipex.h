/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:38:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/09 15:51:22 by yel-yaqi         ###   ########.fr       */
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
# define INFILE 0
# define OUTFILE 1

int		*unpack_fds(int *fds, int argc, char **argv, int *errnos);
void	check_fds(int *fds, int argc, char **argv, int *errnos);
void	pipeline(char **argv, char *paths, int *fds);
int		strictcmp(char *str0, char *str1);
char	*get_paths(char **env);
char	*get_next_path(char **paths, int *path_count);
void	count_chr(char *str, char chr, int *counter);
char	*construct_cmd(char *paths, char *cmd);
void	execute_cmd(int *pipe_fds, char **argvv, int *fds);
char	*first_word(char *str);
void	unpack_argvv(char **argvv, char *paths, char *word_list, char *cmd);

#endif