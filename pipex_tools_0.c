/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tools_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:31:44 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/06 19:24:23 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	*unpack_fds(int *fds, int argc, char **argv, int *errnos)
{
	if (!strictcmp("here_doc", argv[1]))
		fds[0] = get_heredoc_fd(argv[2], errnos);
	else
	{
		fds[0] = open(argv[1], O_RDONLY);
		errnos[0] = errno;
	}
	fds[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (errnos[1] = errno, fds);
}

void	check_fds(int *fds, int argc, char **argv, int *errnos)
{
	if (fds[0] < 0)
	{
		if (fds[1] >= 0)
			close(fds[1]);
		ft_printf("pipex: %s: %s", strerror(errnos[0]), argv[1]);
		exit(EXIT_FAILURE);
	}
	if (fds[1] < 0)
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

int	get_heredoc_fd(char *limiter, int *errnos)
{
	char	*entry;
	int		heredoc_fd;

	heredoc_fd = open("heredoc", O_CREAT | O_RDWR, 0644);
	errnos[0] = errno;
	if (heredoc_fd < 0)
		exit(EXIT_FAILURE);
	ft_printf("heredoc> ");
	entry = get_next_line(STDIN_FILENO);
	while (entry && ft_strncmp(entry, limiter, ft_strlen(limiter)))
	{
		ft_putstr_fd(entry, heredoc_fd);
		free(entry);
		ft_printf("heredoc> ");
		entry = get_next_line(STDIN_FILENO);
	}
	free(entry);
	return (heredoc_fd);
}

