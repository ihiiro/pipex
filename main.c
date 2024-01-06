/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:12:18 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/06 16:26:56 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fds[2];
	int		errnos[2];

	if (argc < 5 || (argc < 6 && !strictcmp("here_doc", argv[1])))
		exit(EXIT_FAILURE);
	check_fds(unpack_fds(fds, argc, argv, errnos), argc, argv, errnos);
	pipeline(fds, errnos, argv, get_paths(env));
	// while (1);
}
