/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tools_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:48:45 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/05 20:12:20 by yel-yaqi         ###   ########.fr       */
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
