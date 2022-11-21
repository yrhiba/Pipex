/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 01:04:46 by yrhiba            #+#    #+#             */
/*   Updated: 2022/11/21 15:26:00 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_format_c(t_print *tab, int c)
{
	if (tab->mines)
	{
		ft_addchar(tab, c);
		ft_addnchar(32, tab->w_nbr - 1, tab);
	}
	else if (tab->zero)
	{
		ft_addnchar('0', tab->w_nbr - 1, tab);
		ft_addchar(tab, c);
	}
	else if (tab->width)
	{
		ft_addnchar(32, tab->w_nbr - 1, tab);
		ft_addchar(tab, c);
	}
	else
		ft_addchar(tab, c);
}
