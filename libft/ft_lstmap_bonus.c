/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:57:48 by yel-yaqi          #+#    #+#             */
/*   Updated: 2023/11/19 18:57:55 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	ptr = NULL;
	while (lst)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (!new)
		{
			ft_lstclear(&ptr, del);
			return (NULL);
		}
		new->content = f(lst->content);
		new->next = NULL;
		ft_lstadd_back(&ptr, new);
		lst = lst->next;
	}
	return (ptr);
}
