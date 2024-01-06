/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tools_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:48:45 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/06 12:23:07 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipeline(int *fds, int *errnos, char **argv, int argc)
{
	(void)errnos;
	(void)argv;
	// int		i;
	pid_t	child_pid;
	int		pipee[2];

	if (argc == 2)
		write_fd_to_fd(fds[0], STDOUT_FILENO);
	else
	{
		pipe(pipee);
		write_fd_to_fd(fds[0], pipee[1]);
		child_pid = fork();
		if (child_pid == 0)
		{
			dup2(pipee[0], STDIN_FILENO);
			char	*argvv[] = {"/usr/bin/grep", "hi", NULL};
			execve(argvv[0], argvv, NULL);
			exit(EXIT_SUCCESS);
		}
		else
		{
			// waitpid(child_pid, NULL, 0);
		}
	}
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

int	get_heredoc_fd(char *limiter, int *errnos)
{
	char	*entry;
	int		heredoc_fd;

	heredoc_fd = open("heredoc", O_CREAT | O_RDWR, 0644);
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
	return (errnos[0] = errno, heredoc_fd);
}
