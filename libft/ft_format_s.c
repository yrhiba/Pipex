/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:14:56 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/21 15:26:19 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format_s(t_print *tab)
{
	char	*s;
	char	*arg;

	arg = va_arg(tab->args, char *);
	if (!arg)
		s = ft_strdup(PNULL);
	else
		s = ft_strdup((const char *)arg);
	if (!s)
		return (tab->error = 1, 0);
	s = ft_format_s_usingflags(s, tab);
	if (!s)
		return (tab->error = 1, 0);
	ft_addstr((const char *)s, tab);
	return (free(s), 0);
}
