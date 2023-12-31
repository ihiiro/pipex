/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:12:18 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/09 15:17:37 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	int		fds[2];
	int		errnos[2];

	if (argc < 5 || (argc < 6 && !strictcmp("here_doc", argv[1])))
		exit(EXIT_FAILURE);
	check_fds(unpack_fds(fds, argc, argv, errnos), argc, argv, errnos);
	if (!strictcmp("here_doc", argv[1]))
		argv += 3;
	else
		argv += 2;
	pipeline(argv, get_paths(env), fds);
	if (!strictcmp("here_doc", *(argv - 2)))
		unlink("heredoc");
	while (wait(NULL) > 0)
		;
}
