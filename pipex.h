/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:38:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/02 15:45:31 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/printf/ft_printf.h"
# include <fcntl.h>
# include <sys/errno.h>

void	print_infile(int infile_fd);
void	execute_cmd(char *filename, char *cmd);
void	pipex(int infile_fd, int outfile_fd, char **argv, int argc);

#endif