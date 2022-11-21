/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:48:25 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/21 15:26:10 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format_p(t_print *tab)
{
	char	*nbr;

	tab->hash = 1;
	nbr = ft_converthex(va_arg(tab->args, unsigned long), LWHEX);
	if (!nbr)
		return (tab->error = 1, -1);
	nbr = ft_format_x_usingflags(nbr, tab, LWPRX, 0);
	if (!nbr)
		return (tab->error = 1, -1);
	ft_addstr(nbr, tab);
	return (free(nbr), 1);
}
