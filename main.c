/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:12:18 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/04 18:38:12 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int	fds[2];
	int	errnos[2];

	check_fds(unpack_fds(fds, argc, argv, errnos), argc, argv, errnos);
	write_fd_to_fd(fds[0], 1);

	// ft_printf("%d %d", fds[0], fds[1]);
}
