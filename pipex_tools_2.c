/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:48:03 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/09 00:25:31 by yel-yaqi         ###   ########.fr       */
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

void	pipeline(char **argv, char *paths, int *fds)
{
	char	*argvv[3];
	int		pipe_fds[2];
	int		i;

	if (pipe(pipe_fds) < 0)
		exit(EXIT_FAILURE);
	i = 0;
	while (1)
	{
		if (!argv[i + 1])
			break ;
		unpack_argvv(argvv, paths, argv[i], first_word(argv[i]));
		if (i == 0)
			dup2(fds[INFILE], STDIN_FILENO);
		else
			dup2(pipe_fds[READ_END], STDIN_FILENO);
		if (pipe(pipe_fds) < 0)
				exit(EXIT_FAILURE);
		execute_cmd(pipe_fds, argvv);
		i++;
	}
	write_fd_to_fd(pipe_fds[READ_END], fds[OUTFILE]);
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

void	unpack_argvv(char **argvv, char *paths, char *word_list, char *cmd)
{
	argvv[0] = construct_cmd(paths, cmd);
	free(cmd);
	if (ft_strchr(word_list, ' '))
		argvv[1] = ft_strchr(word_list, ' ') + 1;
	else
		argvv[1] = NULL;
	argvv[2] = NULL;
}
