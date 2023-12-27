/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:44:41 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/19 19:44:46 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trm;
	int		strt;
	int		end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	strt = 0;
	while (s1[strt] && in_set(s1[strt], set))
		strt++;
	end = ft_strlen(s1) - 1;
	while (end >= 0 && in_set(s1[end], set))
		end--;
	if (end < strt)
	{
		trm = (char *)malloc(sizeof(char));
		if (!trm)
			return (NULL);
		*trm = '\0';
		return ((trm));
	}
	trm = (char *)malloc(sizeof(char) * (end - strt + 2));
	if (!trm)
		return (NULL);
	ft_strlcpy(trm, &s1[strt], end - strt + 2);
	return (trm);
}
