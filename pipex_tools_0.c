/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tools_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:31:44 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/05 18:49:42 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	*unpack_fds(int *fds, int argc, char **argv, int *errnos)
{
	if (argc == 1)
		exit(EXIT_FAILURE);
	fds[0] = open(argv[1], O_RDONLY);
	errnos[0] = errno;
	if (argc == 2)
		return (errnos[1] = -1, fds);
	fds[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (errnos[1] = errno, fds);
}

void	check_fds(int *fds, int argc, char **argv, int *errnos)
{
	if (fds[0] < 0)
	{
		if (errnos[1] != -1 && fds[1] >= 0)
			close(fds[1]);
		ft_printf("pipex: %s: %s", strerror(errnos[0]), argv[1]);
		exit(EXIT_FAILURE);
	}
	if (errnos[1] != -1 && fds[1] < 0)
	{
		if (fds[0] >= 0)
			close(fds[0]);
		ft_printf("pipex: %s: %s", strerror(errnos[1]), argv[argc - 1]);
		exit(EXIT_FAILURE);
	}
}

void	write_fd_to_fd(int fd_read, int fd_write)
{
	char	*bytes;

	bytes = get_next_line(fd_read);
	while (bytes)
	{
		ft_putstr_fd(bytes, fd_write);
		free(bytes);
		bytes = get_next_line(fd_read);
	}
}

int	file_exists(char *filename)
{
	int	fd;

	return (fd = open(filename, O_RDONLY), close(fd), fd);
}

int	is_file(char *symbol)
{
	return (file_exists(symbol) >= 0);
}
