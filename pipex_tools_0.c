/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tools_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:31:44 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/07 17:05:39 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	*unpack_fds(int *fds, int argc, char **argv, int *errnos)
{
	if (!strictcmp("here_doc", argv[1]))
		fds[INFILE] = get_heredoc_fd(argv[2], errnos);
	else
	{
		fds[INFILE] = open(argv[1], O_RDONLY);
		errnos[INFILE] = errno;
	}
	fds[OUTFILE] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (errnos[OUTFILE] = errno, fds);
}

void	check_fds(int *fds, int argc, char **argv, int *errnos)
{
	if (fds[INFILE] < 0)
	{
		if (fds[OUTFILE] >= 0)
			close(fds[OUTFILE]);
		ft_printf("pipex: %s: %s", strerror(errnos[INFILE]), argv[1]);
		exit(EXIT_FAILURE);
	}
	if (fds[OUTFILE] < 0)
	{
		if (fds[INFILE] >= 0)
			close(fds[INFILE]);
		ft_printf("pipex: %s: %s", strerror(errnos[OUTFILE]), argv[argc - 1]);
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
	errnos[INFILE] = errno;
	if (heredoc_fd < 0)
		exit(EXIT_FAILURE);
	ft_printf("heredoc> ");
	entry = get_next_line(STDIN_FILENO);
	while (entry && cmp_to_stdin(limiter, entry))
	{
		ft_putstr_fd(entry, heredoc_fd);
		free(entry);
		ft_printf("heredoc> ");
		entry = get_next_line(STDIN_FILENO);
	}
	free(entry);
	if (heredoc_fd >= 0)
	{
		close(heredoc_fd);
		heredoc_fd = open("heredoc", O_CREAT | O_RDWR, 0644);
		errnos[INFILE] = errno;
	}
	return (heredoc_fd);
}

int	strictcmp(char *str0, char *str1)
{
	size_t	str0_len;

	str0_len = ft_strlen(str0);
	if (!ft_strncmp(str0, str1, str0_len) && ft_strlen(str1) == str0_len)
		return (0);
	else
		return (1);
}
