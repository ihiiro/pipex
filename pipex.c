/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:31:44 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/02 13:49:57 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*prefix_with_bin(char *cmdname)
{
	char	*execve_ready_cmdname;

	execve_ready_cmdname = ft_strjoin("/bin/", cmdname);
	if (!execve_ready_cmdname)
	{
		free(cmdname);
		exit(EXIT_FAILURE);
	}
	free(cmdname);
	return (execve_ready_cmdname);
}

static char	*get_cmdname(char *cmd)
{
	char	*cmdname;

	cmdname = ft_substr(cmd, 0, ft_strchr(cmd, ' ') - cmd);
	if (!cmdname)
		exit(EXIT_FAILURE);
	cmdname = prefix_with_bin(cmdname);
	return (cmdname);
}

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

void	execute_cmd(int fd, char *filename, char *cmd)
{
	(void)fd;
	pid_t	child_pid;
	char	*argv[3];

	child_pid = fork();
	if (child_pid == 0)
	{
		argv[0] = get_cmdname(cmd);
		argv[1] = filename;
		argv[2] = NULL;
		if (execve(argv[0], argv, NULL) < 0)
		{
			ft_printf("pipex: %s: %s", strerror(errno), argv[0]);
			free(argv[0]);
			exit(EXIT_FAILURE);
		}
		free(argv[0]);
		exit(EXIT_SUCCESS);
	}
	else if (child_pid < 0)
		exit(EXIT_FAILURE);
	else
		if (waitpid(child_pid, NULL, 0) == child_pid)
			return;
	return;
}
