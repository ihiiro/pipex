/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tools_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:48:45 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/06 14:23:18 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	pipeline(int *fds, int *errnos, char **argv, int argc)
// {
// 	// (void)errnos;
// 	// (void)argv;
// 	int	*fd[2];

// 	if (pipe(fds) < 0)
// 		exit(EXIT_FAILURE);
	
// }

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

char	*get_next_path(char **paths)
{
	int		i;
	char	*path;
	size_t	dstsize;

	if (!ft_strncmp(*paths, "PATH=", 5))
		*paths += 5;
	i = 0;
	while (paths[0][i] && paths[0][i] != ':')
		i++;
	i++;
	printf("-%d-", i);
	dstsize = sizeof(char) * (i + 1);
	path = (char *)malloc(dstsize);
	if (!path)
		exit(EXIT_FAILURE);
	ft_strlcpy(path, *paths, dstsize);
	*paths += i;
	return (path);
}
