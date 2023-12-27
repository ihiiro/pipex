/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:57:52 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/19 18:01:26 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	fl_size;
	size_t	i;

	if (count != 0 && (count * size) / count != size)
		return (NULL);
	fl_size = count * size;
	ptr = malloc(fl_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < fl_size)
	{
		*(char *)(ptr + i) = 0;
		i++;
	}
	return (ptr);
}
