/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:31:44 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/02 11:01:37 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_infile(int infile_fd)
{
	char	*line;

	line = get_next_line(infile_fd);
	while (line)
	{
		ft_printf("%s", line);
		free(line);
		line = get_next_line(infile_fd);
	}
	close(infile_fd);
	exit(EXIT_SUCCESS);
}
