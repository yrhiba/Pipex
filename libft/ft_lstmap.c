/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 05:44:29 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/21 14:43:45 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*newlst;

	if (!lst || !f || !del)
		return (NULL);
	node = ft_lstnew(f(lst->content));
	if (!node)
		return (NULL);
	newlst = node;
	lst = lst->next;
	while (lst)
	{
		node->next = ft_lstnew(f(lst->content));
		if ((node->next) == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		node = node->next;
		lst = lst->next;
	}
	node->next = NULL;
	return (newlst);
}
