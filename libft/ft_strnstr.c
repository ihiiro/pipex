/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:44:54 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/20 10:47:55 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_n;

	if (!*needle)
		return ((char *)haystack);
	if (needle && !len)
		return (NULL);
	len_n = 0;
	while (*(needle + len_n))
		len_n++;
	while (*haystack && len >= len_n)
	{
		if (!ft_strncmp(haystack, needle, len_n))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
