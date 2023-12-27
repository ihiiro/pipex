/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:33:19 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/19 18:41:46 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	rslt;
	long	tmp;
	int		sign;

	sign = 1;
	rslt = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		tmp = rslt * 10 + *str - '0';
		if (tmp < rslt && sign == 1)
			return (-1);
		if (tmp < rslt && sign == -1)
			return (0);
		rslt = tmp;
		str++;
	}
	return (sign * rslt);
}
