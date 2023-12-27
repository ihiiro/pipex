/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:31:40 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/19 19:31:52 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec_putnbr_fd(long n, int fd, char c)
{
	c = -n % 10 + '0';
	if (!ft_isdigit(c))
		c = n % 10 + '0';
	if (ft_isdigit(-n + '0') || ft_isdigit(n + '0'))
	{
		if (n < 0)
			write(fd, "-", 1);
		write(fd, &c, 1);
		return ;
	}
	rec_putnbr_fd(n / 10, fd, c);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	d;

	if (fd < 0)
		return ;
	d = n;
	rec_putnbr_fd(d, fd, 0);
}
