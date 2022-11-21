/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:04:03 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/21 15:26:23 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format_u(t_print *tab)
{
	char	*nbr;

	nbr = ft_itoa(va_arg(tab->args, unsigned int));
	if (!nbr)
		return (tab->error = 1, -1);
	tab->plus = 0;
	tab->hash = 0;
	tab->space = 0;
	nbr = ft_format_d_usingflags(nbr, tab);
	if (!nbr)
		return (tab->error = 1, -1);
	ft_addstr((const char *)nbr, tab);
	return (free(nbr), 0);
}
