/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:34:09 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/19 17:55:01 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_dst = 0;
	len_src = 0;
	while (*(src + len_src))
		len_src++;
	if (!dst && !dstsize)
		return (len_src);
	while (*(dst + len_dst))
		len_dst++;
	if (dstsize <= len_dst)
		return (dstsize + len_src);
	i = 0;
	while (i < dstsize - len_dst - 1 && *(src + i))
	{
		*(dst + len_dst + i) = *(src + i);
		i++;
	}
	*(dst + len_dst + i) = '\0';
	return (len_src + len_dst);
}
