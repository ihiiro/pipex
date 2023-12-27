/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 10:21:51 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/19 12:23:20 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	while (i >= 1)
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
		i--;
	}
	if (*(s + i) == (char)c)
		return ((char *)s + i);
	return (NULL);
}
