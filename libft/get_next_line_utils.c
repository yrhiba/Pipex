/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 02:57:40 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/21 20:52:46 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fjoin(char *s1, char *s2)
{
	char	*rtn;
	char	*tmp;
	int		i;

	rtn = (char *)malloc(sizeof(char) * (ft_strlc(s1, 0) + ft_strlc(s2, 0)
				+ 1));
	if (!rtn)
		return (NULL);
	tmp = rtn;
	i = 0;
	while (s1[i])
		*tmp++ = s1[i++];
	i = 0;
	while (s2[i])
		*tmp++ = s2[i++];
	*tmp = '\0';
	free(s1);
	return (rtn);
}

int	ft_strlc(char *s, int len0_or_chr1)
{
	int	i;

	i = 0;
	while (s[i] && len0_or_chr1)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	if (!len0_or_chr1)
	{
		while (s[i])
			i++;
		return (i);
	}
	return (-1);
}

t_list_gn	*ft_flstnew(char *content, int fd)
{
	t_list_gn	*node;

	node = (t_list_gn *)malloc(sizeof(t_list_gn));
	if (!node)
		return (NULL);
	node->content = content;
	node->fd = fd;
	node->next = 0;
	return (node);
}

char	*ft_get_content(t_list_gn **list_o, int fd)
{
	t_list_gn	*new;
	t_list_gn	*list;
	char		*rtn;

	list = *list_o;
	while (list)
	{
		if (list->fd == fd)
			return (list->content);
		list = list->next;
	}
	rtn = (char *)malloc(sizeof(char));
	if (!rtn)
		return (NULL);
	*rtn = '\0';
	new = ft_flstnew(rtn, fd);
	if (!new)
	{
		free(rtn);
		return (NULL);
	}
	new->next = *list_o;
	*list_o = new;
	return ((*list_o)->content);
}

void	delete_node(t_list_gn **list, int fd)
{
	t_list_gn	*tmp;
	t_list_gn	*nex;
	t_list_gn	*prev;

	tmp = *list;
	prev = NULL;
	while (tmp)
	{
		nex = tmp->next;
		if (tmp->fd == fd)
		{
			free(tmp->content);
			free(tmp);
			if (prev)
				prev->next = nex;
			else
				*list = nex;
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
