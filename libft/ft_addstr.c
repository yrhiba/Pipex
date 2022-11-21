/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:14:07 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/21 15:25:35 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_addstr(const char *s, t_print *tab)
{
	char	*new;
	size_t	len;
	int		i;
	int		j;

	len = tab->buflen + ft_strlen(s);
	new = (char *)ft_calloc((len + 1), sizeof(char));
	if (!new)
		return (tab->error = 1, -1);
	i = -1;
	while (++i < tab->buflen)
		new[i] = (tab->buff)[i];
	j = -1;
	while (s[++j])
		new[i++] = s[j];
	free(tab->buff);
	tab->buff = new;
	return (tab->buflen = len);
}
