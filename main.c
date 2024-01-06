/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:12:18 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/06 15:52:50 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fds[2];
	int		errnos[2];
	char	*paths;
	int		counter;

	paths = get_paths(env);
	counter = 0;
	printf("%s\n", get_next_path(&paths, &counter));
	check_fds(unpack_fds(fds, argc, argv, errnos), argc, argv, errnos);
	// pipeline(fds, errnos, argv, argc);
	write_fd_to_fd(fds[0], STDOUT_FILENO);
	// while (1);

	// ft_printf("%d %d", fds[0], fds[1]);
}
