/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:41:48 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/19 19:44:02 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint;
	int		i;

	if (s1 == NULL && s2)
		return (ft_strdup(s2));
	if (s2 == NULL && s1)
		return (ft_strdup(s1));
	i = -1;
	joint = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joint)
		return (NULL);
	while (s1[++i])
		joint[i] = s1[i];
	while (*s2)
		joint[i++] = *s2++;
	joint[i] = '\0';
	return (joint);
}
