/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:12:18 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/02 11:04:59 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int	infile_fd;
	int	outfile_fd;

	if (argc <= 1 || (!ft_strncmp(argv[1], argv[argc - 1], ft_strlen(argv[1])) // infile == outfile
			&& ft_strlen(argv[1]) == ft_strlen(argv[argc - 1]) && argc != 2))
		exit(EXIT_SUCCESS);
	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd < 0)
	{
		ft_printf("pipex: %s: %s", strerror(errno), argv[1]);
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
		print_infile(infile_fd);
	outfile_fd = open(argv[argc - 1], O_RDONLY);
	if (outfile_fd < 0 && errno == 2)
		outfile_fd = open(argv[argc - 1], O_CREAT, 0644);
	if (outfile_fd < 0)
	{
		ft_printf("pipex: %s: %s", strerror(errno), argv[argc - 1]);
		close(infile_fd);
		exit(EXIT_FAILURE);
	}
	
}
