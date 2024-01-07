/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:12:18 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/07 13:21:16 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	(void)env;
	int		fds[2];
	int		errnos[2];

	if (argc < 5 || (argc < 6 && !strictcmp("here_doc", argv[1])))
		exit(EXIT_FAILURE);
	check_fds(unpack_fds(fds, argc, argv, errnos), argc, argv, errnos);
	if (!strictcmp("here_doc", argv[1]))
		argv += 3;
	else
		argv += 2;

	int	pipe_fds[2];
	pipe(pipe_fds);
	char	*argvv[] = {"/bin/cat", "-e", NULL};
	execute_cmd(fds[0], pipe_fds[WRITE_END], argvv);
	write_fd_to_fd(pipe_fds[READ_END], 1);
	// while (1);
}
