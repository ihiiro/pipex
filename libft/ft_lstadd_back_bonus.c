/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:52:03 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/19 18:52:10 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		ft_lstadd_front(lst, new);
		return ;
	}
	ptr = *lst;
	while (ptr)
	{
		if (!ptr->next)
		{
			ptr->next = new;
			break ;
		}
		ptr = ptr->next;
	}
}
