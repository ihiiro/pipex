/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:48:22 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/19 19:48:40 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_digits(int n)
{
	int	cnt;

	cnt = 0;
	while (n && ++cnt)
		n /= 10;
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*ascii;
	int		size;
	int		p;

	p = n;
	size = sizeof(char) * (cnt_digits(n + (n == 0)) + 1 + (n < 0));
	ascii = (char *)malloc(size);
	if (!ascii)
		return (NULL);
	if (n < 0)
		ascii[0] = '-';
	ascii[size - sizeof(char)] = '\0';
	size -= sizeof(char) * 2;
	while (size >= 0)
	{
		if (p < 0 && size == 0)
			break ;
		ascii[size] = (-(n < 0) + (n < 0 == 0)) * (n % 10) + '0';
		n /= 10;
		size -= sizeof(char);
	}
	return (ascii);
}
