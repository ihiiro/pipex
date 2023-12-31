/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:48:03 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/09 15:54:27 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipeline(char **argv, char *paths, int *fds)
{
	char	*argvv[3];
	int		pipe_fds[2];
	int		i;

	i = 0;
	while (1)
	{
		if (!argv[i + 1])
			break ;
		unpack_argvv(argvv, paths, argv[i], first_word(argv[i]));
		pipe(pipe_fds);
		if (!argv[i + 2])
			dup2(fds[OUTFILE], pipe_fds[WRITE_END]);
		execute_cmd(pipe_fds, argvv, fds);
		close(fds[INFILE]);
		fds[INFILE] = pipe_fds[READ_END];
		close(pipe_fds[WRITE_END]);
		free(argvv[0]);
		i++;
	}
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
