/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:40:19 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/02 15:54:47 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int infile_fd, int outfile_fd, char **argv, int argc)
{
	int	i;
	(void)infile_fd;
	(void)outfile_fd;
	i = 2;
	while (i < argc)
	{
		execute_cmd(argv[1], argv[i]);
		i++;
	}
}
