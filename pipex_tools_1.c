/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tools_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:48:45 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/06 15:51:57 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	strictcmp(char *str0, char *str1)
{
	size_t	str0_len;

	str0_len = ft_strlen(str0);
	if (!ft_strncmp(str0, str1, str0_len) && ft_strlen(str1) == str0_len)
		return (0);
	else
		return (1);
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
		count_char(*paths, ':', path_count);
		*path_count += 1;
	}
	if (!*path_count)
		return (NULL);
	i = 0;
	while (paths[0][i] && paths[0][i] != ':')
		i++;
	dstsize = sizeof(char) * (i + 1);
	path = (char *)malloc(dstsize);
	if (!path)
		exit(EXIT_FAILURE);
	ft_strlcpy(path, *paths, dstsize);
	*paths += i + 1;
	return (*path_count -= 1, path);
}

void	count_char(char *str, char chr, int *counter)
{
	while (*str)
	{
		if (*str == chr)
			*counter += 1;
		str++;
	}
}
