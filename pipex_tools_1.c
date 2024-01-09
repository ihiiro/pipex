/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tools_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:48:45 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/09 10:31:49 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(int *pipe_fds, char **argvv)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		dup2(pipe_fds[WRITE_END], STDOUT_FILENO);
		execve(argvv[0], argvv, NULL);
	}
	else
		close(pipe_fds[WRITE_END]);
}

char	*get_paths(char **env)
{
	while (*env)
	{
		if (!ft_strncmp(*env, "PATH", 4))
			return (*env);
		env++;
	}
	return (NULL);
}

char	*get_next_path(char **paths, int *path_count)
{
	int		i;
	char	*path;
	size_t	dstsize;

	if (!ft_strncmp(*paths, "PATH=", 5))
	{
		*paths += 5;
		count_chr(*paths, ':', path_count);
		*path_count += 1;
	}
	if (!*path_count)
		return (NULL);
	i = 0;
	while (paths[0][i] && paths[0][i] != ':')
		i++;
	dstsize = sizeof(char) * (i + 2);
	path = (char *)malloc(dstsize);
	if (!path)
		exit(EXIT_FAILURE);
	ft_strlcpy(path, *paths, dstsize);
	path[dstsize - 2] = '/';
	path[dstsize - 1] = '\0';
	*paths += i + 1;
	return (*path_count -= 1, path);
}

void	count_chr(char *str, char chr, int *counter)
{
	while (*str)
	{
		if (*str == chr)
			*counter += 1;
		str++;
	}
}

char	*construct_cmd(char *paths, char *cmd)
{
	char	*path_to_executable;
	char	*path;
	int		path_count;

	path = get_next_path(&paths, &path_count);
	while (path)
	{
		path_to_executable = ft_strjoin(path, cmd);
		free(path);
		if (access(path_to_executable, F_OK | X_OK) == 0)
			return (path_to_executable);
		free(path_to_executable);
		path = get_next_path(&paths, &path_count);
	}
	return (NULL);
}
