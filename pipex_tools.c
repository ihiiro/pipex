/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:31:44 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/04 13:49:57 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	*unpack_fds(int **fds, int argc, char **argv, int *errnos) // perms
{
	if (argc == 1)
		exit(EXIT_FAILURE);
	*fds[0] = open(argv[1], O_RDONLY);
	errnos[0] = errno;
	*fds[1] = open(argv[argc - 1], O_WRONLY | O_CREAT /*| O_TRUNC */);
	return (errnos[1] = errno, *fds);
}

void	eval_fds(int *fds, int argc, char **argv, int *errnos) // return number of useable fds
{
	if (argc == 2)
		close(fds[1]);
	if (fds[0] < 0)
	{
		ft_printf("pipex: %s: %s", strerror(errnos[0]), argv[0]);
		exit(EXIT_FAILURE);
	}
	if (fds[1] < 0)
	{
		ft_printf("pipex: %s: %s", strerror(errnos[1]), argv[argc - 1]);
		exit(EXIT_FAILURE);
	}
}
