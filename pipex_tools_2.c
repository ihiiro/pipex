/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:48:03 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/07 15:48:51 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	cmp_to_stdin(char *str, char *stdin_str)
{
	size_t	str_len;
	size_t	stdin_str_len;

	str_len = ft_strlen(str);
	stdin_str_len = ft_strlen(stdin_str);
	if (!ft_strncmp(str, stdin_str, str_len) && stdin_str_len == str_len + 1)
		return (0);
	else
		return (1);
}

void	pipeline(int argc, char **argv, char *paths)
{
	char	*argvv[3];
	char	*cmd;
	int		pipe_fds[2];
	int		i;
	int		path_count;

	if (pipe(pipe_fds) < 0)
		exit(EXIT_FAILURE);
	i = 0;
	while (1)
	{
		if (!argv[i + 1])
			break ;
		cmd = first_word(argv[i]);
		argvv[0] = construct_cmd(paths, cmd);
		free(cmd);
		argvv[1] = ft_strchr(argv[i], ' ') + 1;
		argvv[2] = NULL;
		if (i == 0)
			fds[0]
		else
			
		i++;
	}
}

char	*first_word(char *str)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] != ' ')
		i++;
	word = ft_substr(str, 0, i);
	if (!word)
		exit(EXIT_FAILURE);
	return (word);
}
